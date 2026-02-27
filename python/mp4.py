from manim import *

class SquareDifference(Scene):
    """a² - b² = (a+b)(a-b) 的几何解释动画"""
    
    def construct(self):
        # 设置颜色方案
        self.camera.background_color = "#f5f5f5"
        
        # 标题
        title = Text("平方差公式的几何解释", color=BLUE, font_size=48)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(1)
        
        # 公式
        formula = MathTex("a^2 - b^2 = (a+b)(a-b)", color=BLACK, font_size=42)
        formula.next_to(title, DOWN, buff=0.5)
        self.play(Write(formula))
        self.wait(1)
        
        # 参数
        a_val = 4
        b_val = 2
        
        # 创建坐标轴
        ax = Axes(
            x_range=[-1, 7, 1],
            y_range=[-1, 5, 1],
            x_length=8,
            y_length=6,
            axis_config={"color": GRAY},
        )
        ax.to_edge(LEFT)
        
        # 第一阶段：两个独立的正方形
        stage1_text = Text("1. 两个独立的正方形", color=PURPLE, font_size=36)
        stage1_text.next_to(ax, DOWN, buff=0.5)
        
        # 大正方形 a²
        square_a = Square(side_length=a_val, color=BLUE, fill_opacity=0.3)
        square_a.move_to(ax.c2p(a_val/2, a_val/2, 0))
        label_a = MathTex(f"a^2 = {a_val}^2", color=BLUE, font_size=30)
        label_a.next_to(square_a, UP, buff=0.3)
        
        # 小正方形 b²
        square_b = Square(side_length=b_val, color=RED, fill_opacity=0.3)
        square_b.move_to(ax.c2p(a_val + 1 + b_val/2, b_val/2, 0))
        label_b = MathTex(f"b^2 = {b_val}^2", color=RED, font_size=30)
        label_b.next_to(square_b, UP, buff=0.3)
        
        self.play(
            Write(stage1_text),
            Create(square_a),
            Write(label_a),
            Create(square_b),
            Write(label_b)
        )
        self.wait(1)
        
        # 计算差值
        diff_value = a_val**2 - b_val**2
        diff_text = MathTex(
            f"a^2 - b^2 = {a_val}^2 - {b_val}^2 = {diff_value}",
            color=BLACK, font_size=36
        )
        diff_text.to_edge(RIGHT)
        diff_text.shift(UP)
        
        self.play(Write(diff_text))
        self.wait(1)
        
        # 第二阶段：将小正方形放入大正方形
        stage2_text = Text("2. 将小正方形放入大正方形", color=PURPLE, font_size=36)
        stage2_text.next_to(ax, DOWN, buff=0.5)
        
        self.play(
            ReplacementTransform(stage1_text, stage2_text),
            square_b.animate.move_to(ax.c2p(a_val - b_val + b_val/2, a_val - b_val + b_val/2, 0)),
            FadeOut(label_b)
        )
        self.wait(1)
        
        # 添加切割线
        line_v = Line(
            ax.c2p(a_val - b_val, 0, 0),
            ax.c2p(a_val - b_val, a_val, 0),
            color=GREEN, stroke_width=3
        )
        line_h = Line(
            ax.c2p(0, a_val - b_val, 0),
            ax.c2p(a_val, a_val - b_val, 0),
            color=GREEN, stroke_width=3
        )
        
        self.play(Create(line_v), Create(line_h))
        self.wait(1)
        
        # 第三阶段：标记三个区域
        stage3_text = Text("3. 分割成三个区域", color=PURPLE, font_size=36)
        stage3_text.next_to(ax, DOWN, buff=0.5)
        
        self.play(Transform(stage2_text, stage3_text))
        
        # 区域1: (a-b) × a
        rect1 = Rectangle(
            width=a_val - b_val, height=a_val,
            color=GREEN, fill_opacity=0.3, fill_color=GREEN
        )
        rect1.move_to(ax.c2p((a_val - b_val)/2, a_val/2, 0))
        label1 = MathTex(f"(a-b) \\times a", color=GREEN, font_size=24)
        label1.move_to(rect1.get_center())
        
        # 区域2: b × (a-b)
        rect2 = Rectangle(
            width=b_val, height=a_val - b_val,
            color=ORANGE, fill_opacity=0.3, fill_color=ORANGE
        )
        rect2.move_to(ax.c2p(a_val - b_val + b_val/2, (a_val - b_val)/2, 0))
        label2 = MathTex(f"b \\times (a-b)", color=ORANGE, font_size=24)
        label2.move_to(rect2.get_center())
        
        # 区域3: b² (挖去的部分)
        rect3 = Square(side_length=b_val, color=RED, fill_opacity=0.1)
        rect3.move_to(ax.c2p(a_val - b_val + b_val/2, a_val - b_val + b_val/2, 0))
        label3 = MathTex(f"b^2", color=RED, font_size=24)
        label3.move_to(rect3.get_center())
        
        self.play(
            FadeIn(rect1), Write(label1),
            FadeIn(rect2), Write(label2),
            FadeIn(rect3), Write(label3)
        )
        self.wait(1)
        
        # 第四阶段：重组成长方形
        stage4_text = Text("4. 重组成新长方形", color=PURPLE, font_size=36)
        stage4_text.next_to(ax, DOWN, buff=0.5)
        
        self.play(Transform(stage3_text, stage4_text))
        
        # 移动第一个长方形
        self.play(
            rect1.animate.move_to(ax.c2p((a_val - b_val)/2, a_val/2, 0)),
            label1.animate.move_to(rect1.get_center())
        )
        
        # 移动并旋转第二个长方形
        target_x = a_val - b_val + b_val/2 + 0.5
        target_y = (a_val - b_val)/2
        
        self.play(
            rect2.animate.move_to(ax.c2p(target_x, target_y, 0)),
            label2.animate.move_to(rect2.get_center())
        )
        
        # 合并成长方形
        final_rect = Rectangle(
            width=a_val + b_val, height=a_val - b_val,
            color=PURPLE, fill_opacity=0.2, fill_color=PURPLE,
            stroke_width=4
        )
        final_rect.move_to(ax.c2p((a_val + b_val)/2, (a_val - b_val)/2, 0))
        
        label_final = MathTex(
            f"(a+b)(a-b) = {a_val + b_val} \\times {a_val - b_val} = {diff_value}",
            color=PURPLE, font_size=30
        )
        label_final.next_to(final_rect, DOWN, buff=0.5)
        
        self.play(
            FadeOut(rect1), FadeOut(rect2),
            FadeOut(label1), FadeOut(label2),
            FadeOut(rect3), FadeOut(label3),
            Create(final_rect),
            Write(label_final)
        )
        self.wait(1)
        
        # 最终验证
        final_formula = MathTex(
            f"a^2 - b^2 = {a_val}^2 - {b_val}^2 = {diff_value} = ({a_val}+{b_val})({a_val}-{b_val}) = {a_val+b_val} \\times {a_val-b_val}",
            color=GREEN, font_size=36
        )
        final_formula.next_to(title, DOWN, buff=1)
        
        self.play(
            FadeOut(formula),
            FadeOut(diff_text),
            ReplacementTransform(label_final, final_formula)
        )
        self.wait(2)
        
        # 淡出所有
        self.play(*[FadeOut(mob) for mob in self.mobjects])
        self.wait(1)

class AnimatedSquareDifference(Scene):
    """带平滑过渡的平方差公式动画"""
    
    def construct(self):
        # 设置背景
        self.camera.background_color = "#0a0a0a"
        
        # 标题
        title = Text("a² - b² = (a+b)(a-b)", color=YELLOW, font_size=54)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(1)
        
        # 参数
        a = 4
        b = 2
        
        # 创建第一个正方形
        square1 = Square(side_length=a, color=BLUE, fill_opacity=0.5)
        square1.shift(LEFT * 3)
        label1 = MathTex(f"a^2 = {a}^2", color=BLUE).next_to(square1, DOWN)
        
        self.play(Create(square1), Write(label1))
        self.wait(0.5)
        
        # 创建第二个正方形
        square2 = Square(side_length=b, color=RED, fill_opacity=0.5)
        square2.shift(RIGHT * 3)
        label2 = MathTex(f"b^2 = {b}^2", color=RED).next_to(square2, DOWN)
        
        self.play(Create(square2), Write(label2))
        self.wait(1)
        
        # 移动小正方形
        target_pos = square1.get_center() + np.array([a - b, a - b, 0])/2
        self.play(
            square2.animate.move_to(target_pos),
            FadeOut(label2)
        )
        self.wait(1)
        
        # 添加分割线
        line_v = Line(
            square1.get_left() + np.array([a - b, 0, 0]),
            square1.get_left() + np.array([a - b, a, 0]),
            color=GREEN
        )
        line_h = Line(
            square1.get_bottom() + np.array([0, a - b, 0]),
            square1.get_bottom() + np.array([a, a - b, 0]),
            color=GREEN
        )
        
        self.play(Create(line_v), Create(line_h))
        self.wait(1)
        
        # 高亮三个区域
        rect1 = Rectangle(
            width=a - b, height=a,
            color=GREEN, fill_opacity=0.3
        ).move_to(square1.get_center() + np.array([-(b)/2, 0, 0]))
        
        rect2 = Rectangle(
            width=b, height=a - b,
            color=ORANGE, fill_opacity=0.3
        ).move_to(square1.get_center() + np.array([(a - b)/2, -(b)/2, 0]))
        
        rect3 = Square(
            side_length=b,
            color=RED, fill_opacity=0.3
        ).move_to(square1.get_center() + np.array([(a - b)/2, (a - b)/2, 0]))
        
        self.play(
            FadeIn(rect1),
            FadeIn(rect2),
            FadeIn(rect3)
        )
        self.wait(1)
        
        # 重组动画
        self.play(
            rect1.animate.shift(DOWN * (a - b)/2 + LEFT * (a - b)/2),
            rect2.animate.shift(UP * b/2 + RIGHT * b/2),
            FadeOut(rect3),
            FadeOut(line_v), FadeOut(line_h)
        )
        self.wait(1)
        
        # 显示最终长方形
        final_rect = Rectangle(
            width=a + b, height=a - b,
            color=YELLOW, fill_opacity=0.3
        ).move_to(ORIGIN)
        
        final_label = MathTex(
            f"(a+b)(a-b) = {a+b} \\times {a-b} = {a**2 - b**2}",
            color=YELLOW
        ).next_to(final_rect, DOWN)
        
        self.play(
            Transform(rect1, final_rect),
            Transform(rect2, final_rect),
            FadeOut(square1), FadeOut(square2),
            FadeOut(label1)
        )
        self.play(Write(final_label))
        self.wait(2)
        
        # 最终公式
        final_formula = MathTex(
            f"{a}^2 - {b}^2 = ({a}+{b})({a}-{b}) = {a+b} \\times {a-b} = {a**2 - b**2}",
            color=GREEN, font_size=42
        )
        final_formula.next_to(title, DOWN, buff=1)
        
        self.play(Transform(final_label, final_formula))
        self.wait(2)

class DetailedSquareDifference(Scene):
    """详细讲解平方差公式"""
    
    def construct(self):
        # 标题
        title = Text("平方差公式详解", color=BLUE, font_size=48)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(1)
        
        # 公式
        formula = MathTex(
            "a^2 - b^2 = (a+b)(a-b)",
            color=YELLOW, font_size=60
        )
        formula.next_to(title, DOWN, buff=0.8)
        self.play(Write(formula))
        self.wait(2)
        
        # 代数推导
        derivation = VGroup(
            MathTex("a^2 - b^2"),
            MathTex("= a^2 - ab + ab - b^2"),
            MathTex("= a(a - b) + b(a - b)"),
            MathTex("= (a - b)(a + b)")
        ).arrange(DOWN, aligned_edge=LEFT, buff=0.5)
        derivation.next_to(formula, DOWN, buff=1)
        derivation.shift(LEFT * 2)
        
        # 逐行显示推导
        self.play(Write(derivation[0]))
        self.wait(1)
        
        self.play(Write(derivation[1]))
        self.play(derivation[1].animate.set_color(GREEN))
        self.wait(1)
        
        self.play(Write(derivation[2]))
        self.play(derivation[2].animate.set_color(ORANGE))
        self.wait(1)
        
        self.play(Write(derivation[3]))
        self.play(derivation[3].animate.set_color(RED))
        self.wait(2)
        
        # 数值例子
        example = MathTex(
            "5^2 - 3^2 = 25 - 9 = 16 = (5+3)(5-3) = 8 \\times 2",
            color=BLUE, font_size=44
        )
        example.next_to(derivation, DOWN, buff=1)
        example.shift(RIGHT * 2)
        
        self.play(Write(example))
        self.wait(2)
        
        # 应用场景
        applications = Text(
            "应用：\n• 因式分解\n• 快速计算\n• 解二次方程",
            font_size=36, line_spacing=0.5
        )
        applications.to_edge(RIGHT)
        applications.shift(UP)
        
        self.play(Write(applications))
        self.wait(2)

# 运行动画
if __name__ == "__main__":
    # 渲染第一个动画
    scene = SquareDifference()
    scene.render()
    
    # 或者使用命令行：
    # manim -pql mp4.py SquareDifference
    # manim -pqh mp4.py SquareDifference  # 高质量