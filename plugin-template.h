// Fanqie.h
#ifndef PLUGIN_TEMPLATE_H
#define PLUGIN_TEMPLATE_H

#include "IPlugin.h"
#include "utils/utils.h"
// #include "utils/db.h"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <vector>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;

class PluginTemplate : public IPlugin
{
public:
    std::string getName() const override{}

    void init() override{}

    string getAuthor() override {}

    void getCover() override {}

    string getTitle() override {}

    // void testDB()
    // {
    //     // DB db = DB("cache.db");
    //     this->db.createTable("test");
    // }

    // void unload() override
    // {
    //     std::cout << "MyPlugin is unloading!" << std::endl;
    // }

protected:
    string plugin_id = "plugin-template";
    string plugin_name = "Plugin Template";
    string site_name = "Site Name";
    string site_url = "https://example.com";

    string detail_api_url;
    string index_api_url;

    vector<unordered_map<string, string>> getIndex() override {}

    string getIndexPage() override {}
};
#endif // PLUGIN_TEMPLATE_H