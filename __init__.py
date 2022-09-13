from .bxx.core import core

import importlib

bl_info = {
    "name": "WoW Blender Studio - C++ Tests",
    "author": "IHM",
    "version": (1, 0),
    "blender": (3, 0, 0),
    "description": "",
    "category": "Import-Export"
}

def register():
    core.register()

def unregister():
    core.unregister()

if __name__ == "__main__":
    register()