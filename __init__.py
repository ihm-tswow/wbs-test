from .bxx.core import core

import importlib

bl_info = {
    "name": "BXX Tests",
    "author": "IHM",
    "version": (1, 0),
    "blender": (3, 0, 0),
    "description": "Test suite for bxx",
    "category": "Import-Export"
}

def register():
    core.register()

def unregister():
    core.unregister()

if __name__ == "__main__":
    register()