from .bxx.core import core
from . import preferences

import importlib

bl_info = {
    "name": "Your Plugin",
    "author": "Your Name",
    "version": (1, 0),
    "blender": (3, 0, 0),
    "description": "Your Description",
    "category": "Import-Export"
}

def register():
    importlib.reload(preferences)
    preferences.register()
    core.register()

def unregister():
    preferences.unregister()
    core.unregister()

if __name__ == "__main__":
    register()