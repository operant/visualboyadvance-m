#include "../autoupdater.h"
#include "../../../common/version_cpp.h"
#include "winsparkle-wrapper.h"


void initAutoupdater()
{
    wxString version(vbam_version);
    size_t index = version.Find("-");
    if (index != wxString::npos) // even if we are a nightly, only check latest stable version
        version = version.SubString(0, index - 1);
    win_sparkle_set_appcast_url("http://data.vba-m.com/appcast.xml");
    win_sparkle_set_app_details(L"visualboyadvance-m", L"VisualBoyAdvance-M", version.wc_str());
    win_sparkle_init();
}


void checkUpdatesUi()
{
    win_sparkle_check_update_with_ui();
}


void shutdownAutoupdater()
{
    win_sparkle_cleanup();
}
