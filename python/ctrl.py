import keyboard
import pythoncom
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from ctypes import POINTER, cast
from comtypes import CLSCTX_ALL
import json
import os

# 配置文件路径
CONFIG_FILE = "audio_settings.json"

# 全局变量保存音量状态
current_mic_volume = None
current_speaker_volume = None

def save_settings():
    """保存当前音量设置到文件"""
    settings = {
        'mic_volume': current_mic_volume,
        'speaker_volume': current_speaker_volume
    }
    with open(CONFIG_FILE, 'w') as f:
        json.dump(settings, f)

def load_settings():
    """从文件加载音量设置"""
    if os.path.exists(CONFIG_FILE):
        with open(CONFIG_FILE, 'r') as f:
            settings = json.load(f)
            return settings.get('mic_volume'), settings.get('speaker_volume')
    return None, None

def get_microphone_volume():
    """获取当前麦克风音量级别"""
    pythoncom.CoInitialize()
    try:
        devices = AudioUtilities.GetMicrophone()
        interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        mic_volume = cast(interface, POINTER(IAudioEndpointVolume))
        volume = mic_volume.GetMasterVolumeLevelScalar()
        return volume
    except Exception as e:
        print(f"获取麦克风音量失败: {e}")
        return None
    finally:
        pythoncom.CoUninitialize()

def set_microphone_volume(level):
    """设置麦克风音量级别"""
    pythoncom.CoInitialize()
    try:
        level = max(0.0, min(1.0, level))
        devices = AudioUtilities.GetMicrophone()
        interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        mic_volume = cast(interface, POINTER(IAudioEndpointVolume))
        mic_volume.SetMasterVolumeLevelScalar(level, None)
        return True
    except Exception as e:
        print(f"设置麦克风音量失败: {e}")
        return False
    finally:
        pythoncom.CoUninitialize()

def get_speaker_volume():
    """获取当前扬声器音量级别"""
    pythoncom.CoInitialize()
    try:
        devices = AudioUtilities.GetSpeakers()
        interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        volume = cast(interface, POINTER(IAudioEndpointVolume))
        return volume.GetMasterVolumeLevelScalar()
    except Exception as e:
        print(f"获取扬声器音量失败: {e}")
        return None
    finally:
        pythoncom.CoUninitialize()

def set_speaker_volume(level):
    """设置扬声器音量级别"""
    pythoncom.CoInitialize()
    try:
        level = max(0.0, min(1.0, level))
        devices = AudioUtilities.GetSpeakers()
        interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        volume = cast(interface, POINTER(IAudioEndpointVolume))
        volume.SetMasterVolumeLevelScalar(level, None)
        return True
    except Exception as e:
        print(f"设置扬声器音量失败: {e}")
        return False
    finally:
        pythoncom.CoUninitialize()

def mute_audio():
    """将麦克风和扬声器静音"""
    global current_mic_volume, current_speaker_volume
    
    # 获取当前音量并保存
    current_mic_volume = get_microphone_volume()
    current_speaker_volume = get_speaker_volume()
    save_settings()
    
    # 设置静音
    mic_result = set_microphone_volume(0.0)
    speaker_result = set_speaker_volume(0.0)
    
    if mic_result and speaker_result:
        print("音频已静音")
    else:
        print("音频静音操作部分失败")

def restore_audio():
    """智能恢复音量"""
    global current_mic_volume, current_speaker_volume
    
    # 从文件加载保存的音量
    loaded_mic, loaded_speaker = load_settings()
    if loaded_mic is not None:
        current_mic_volume = loaded_mic
    if loaded_speaker is not None:
        current_speaker_volume = loaded_speaker
    
    # 获取当前实际音量
    current_mic = get_microphone_volume()
    current_speaker = get_speaker_volume()
    
    # 麦克风恢复逻辑
    mic_result = True
    if current_mic_volume is not None:
        if current_mic is not None and current_mic > 0:
            print("麦克风当前已有音量，不进行恢复")
        else:
            mic_result = set_microphone_volume(current_mic_volume)
            print("麦克风音量已恢复")
    
    # 扬声器恢复逻辑
    speaker_result = True
    if current_speaker_volume is not None:
        if current_speaker is not None and current_speaker > 0:
            print("扬声器当前已有音量，不进行恢复")
        else:
            speaker_result = set_speaker_volume(current_speaker_volume)
            print("扬声器音量已恢复")
    
    if not (mic_result and speaker_result):
        print("音频恢复操作部分失败")

# 初始化时加载保存的设置
current_mic_volume, current_speaker_volume = load_settings()

# 设置热键监听
keyboard.add_hotkey('ctrl+4', mute_audio)
keyboard.add_hotkey('ctrl+3', restore_audio)

print("Windows音频控制程序已启动")
print("按下 Ctrl+4 静音麦克风和扬声器")
print("按下 Ctrl+3 智能恢复音量（仅在静音状态下恢复）")
print("按 Ctrl+C 退出程序")

try:
    keyboard.wait()
except KeyboardInterrupt:
    print("\n程序已退出")