import sys
import ast
import operator
from fractions import Fraction

from PySide6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout,
    QHBoxLayout, QLineEdit, QPushButton,
    QLabel, QComboBox
)
from PySide6.QtGui import QPixmap
from PySide6.QtCore import Qt

import matplotlib
matplotlib.use("Agg")

import matplotlib.pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg


# 表达式解析
ops = {
    ast.Add: operator.add,
    ast.Sub: operator.sub,
    ast.Mult: operator.mul,
    ast.Div: operator.truediv,
    ast.USub: operator.neg
}

def eval_expr(expr):
    def _eval(node):

        if isinstance(node, ast.Constant):
            return Fraction(node.value)

        elif isinstance(node, ast.BinOp):
            return ops[type(node.op)](
                _eval(node.left),
                _eval(node.right)
            )

        elif isinstance(node, ast.UnaryOp):
            return ops[type(node.op)](
                _eval(node.operand)
            )

        raise Exception("非法表达式")

    return _eval(ast.parse(expr, mode='eval').body)


# Fraction → LaTeX
def fraction_to_latex(frac):
    return rf"$\frac{{{frac.numerator}}}{{{frac.denominator}}}$"


# LaTeX → QPixmap
def latex_to_pixmap(latex):

    import numpy as np
    from PySide6.QtGui import QImage, QPixmap
    from matplotlib.backends.backend_agg import FigureCanvasAgg
    import matplotlib.pyplot as plt

    fig = plt.figure(figsize=(2, 2), dpi=150)
    fig.patch.set_alpha(0)

    canvas = FigureCanvasAgg(fig)

    fig.text(
        0.5,
        0.5,
        latex,
        ha="center",
        va="center",
        fontsize=28
    )

    canvas.draw()

    width, height = canvas.get_width_height()

    buf = np.frombuffer(
        canvas.buffer_rgba(),
        dtype=np.uint8
    ).reshape(height, width, 4)

    image = QImage(
        buf.data,
        width,
        height,
        4 * width,
        QImage.Format_RGBA8888
    )

    pixmap = QPixmap.fromImage(image)

    plt.close(fig)

    return pixmap

# 主窗口
class MainWindow(QWidget):

    def __init__(self):
        super().__init__()

        self.setWindowTitle("LaTeX 分数计算器")
        self.resize(500, 300)

        layout = QVBoxLayout()

        row = QHBoxLayout()

        # 分数1
        self.num1 = QLineEdit()
        self.den1 = QLineEdit()

        f1 = QVBoxLayout()
        f1.addWidget(self.num1)
        f1.addWidget(QLabel("────", alignment=Qt.AlignCenter))
        f1.addWidget(self.den1)

        # 分数2
        self.num2 = QLineEdit()
        self.den2 = QLineEdit()

        f2 = QVBoxLayout()
        f2.addWidget(self.num2)
        f2.addWidget(QLabel("────", alignment=Qt.AlignCenter))
        f2.addWidget(self.den2)

        # 运算符
        self.op = QComboBox()
        self.op.addItems(["+", "-", "*", "/"])

        # 结果显示
        self.result = QLabel()
        self.result.setAlignment(Qt.AlignCenter)

        row.addLayout(f1)
        row.addWidget(self.op)
        row.addLayout(f2)
        row.addWidget(QLabel("="))
        row.addWidget(self.result)

        layout.addLayout(row)

        btn = QPushButton("计算")
        btn.clicked.connect(self.calculate)

        layout.addWidget(btn)

        self.setLayout(layout)


    def calculate(self):

        try:

            f1 = Fraction(
                eval_expr(self.num1.text()),
                eval_expr(self.den1.text())
            )

            f2 = Fraction(
                eval_expr(self.num2.text()),
                eval_expr(self.den2.text())
            )

            op = self.op.currentText()

            if op == "+":
                res = f1 + f2
            elif op == "-":
                res = f1 - f2
            elif op == "*":
                res = f1 * f2
            else:
                res = f1 / f2

            latex = fraction_to_latex(res)

            pixmap = latex_to_pixmap(latex)

            self.result.setPixmap(pixmap)

        except Exception as e:
            print(e)


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())