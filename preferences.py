import bpy

class preferences(bpy.types.AddonPreferences):
    bl_idname = __package__

    auto_reload_scripts: bpy.props.BoolProperty(
        name = "Auto-load scripts",
        default = False
    )

    loaded_build_type: bpy.props.EnumProperty(
        name = "Loaded Build Type",
        default = "Debug",
        items = [
            ("Debug","Debug",""),
            ("RelWithDebInfo","RelWithDebInfo",""),
            ("Release","Release",""),
            ("MinSizeRel","MinSizeRel","")
        ]
    )

    def draw(self, context):
        self.layout.prop(self, "project_path")
        self.layout.prop(self, "auto_reload_scripts")

    @staticmethod
    def get(key,default = None):
        prefs = bpy.context.preferences.addons[__package__].preferences
        return getattr(prefs,key) if hasattr(prefs,key) else default

def register():
    bpy.utils.register_class(preferences)

def unregister():
    bpy.utils.unregister_class(preferences)