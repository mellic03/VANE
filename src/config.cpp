#include <vane/config.hpp>


vane::CfgParser &vane::GetConfig()
{
    static CfgParser conf("vane.cfg");
    return conf;
}
