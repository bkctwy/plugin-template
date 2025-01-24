#include "plugin-template.h"

extern "C"
{
    IPlugin *createPlugin()
    {
        return new PluginTemplate();
    }
}