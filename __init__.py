from .bxx.core import core

import importlib

bl_info = {
    "name": "Test Plugin",
    "author": "Your Name",
    "version": (1, 0),
    "blender": (3, 0, 0),
    "description": "Your Description",
    "category": "Import-Export"
}

def register():
    print("package is ",__package__)
    core.register()

def unregister():
    core.unregister()

if __name__ == "__main__":
    register()