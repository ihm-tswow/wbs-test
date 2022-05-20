import bpy

class preferences(bpy.types.AddonPreferences):
    bl_idname = __package__

    demo_preference: bpy.props.StringProperty(
        name = "Demo Preference",
        default = "Default Value",
    )

    def draw(self, context):
        self.layout.prop(self, "demo_preference")

    @staticmethod
    def get(key,default = None):
        prefs = bpy.context.preferences.addons[__package__].preferences
        return getattr(prefs,key) if hasattr(prefs,key) else default

def register():
    bpy.utils.register_class(preferences)

def unregister():
    bpy.utils.unregister_class(preferences)