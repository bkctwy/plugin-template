// IPlugin.h
#ifndef IPLUGIN_H
#define IPLUGIN_H

#include "utils/db.h"
#include <string>
#include <cpr/cpr.h>
#include <fmt/format.h>
// #include <json/json.h>
#include <fstream>
#include <unordered_map>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class IPlugin
{
public:
    IPlugin()
    {
        this->readConfig();
        this->db = DB(this->db_path);
    }

    virtual ~IPlugin() = default;
    virtual string getName() const = 0;
    virtual void init() = 0;

    virtual vector<unordered_map<string, string>> getIndex() = 0;
    virtual string getTitle() = 0;
    virtual string getAuthor() = 0;
    virtual void getCover() = 0;

    void setId(string id)
    {
        this->id = id;
    }

    string getId()
    {
        return this->id;
    }

    // virtual void unload() = 0;
    virtual void unload() {};

protected:
    string plugin_name;

    string id;
    string title;
    string site_name;
    string site_url;
    string author;
    string index_page_text;
    string index_page_url;
    vector<unordered_map<string, string>> index_data;

    // config.json
    string data_folder;
    string novels_folder;
    string covers_folder;
    string logs_folder;
    string db_path = "cache.db";
    string sleep_time;
    string max_workers;

    DB db = DB(db_path);

    // virtual bool isDownloaded();
    // virtual bool isFull();

    // virtual string getIndexPage() = 0;
    virtual string getIndexPage()
    {
        if (this->index_page_text.empty())
        {
            cpr::Response response = cpr::Get(cpr::Url{this->index_page_url});
            fmt::println(response.text);
            this->index_page_text = response.text;
        }
        return this->index_page_text;
    };

    void readConfig()
    {
        ifstream config_file("config.json");
        json data = json::parse(config_file);
        this->data_folder = data["data_folder"].get<string>();
        this->novels_folder = data_folder + "/" + data["novels_folder"].get<string>();
        this->covers_folder = data_folder + "/" + data["covers_folder"].get<string>();
        this->logs_folder = data_folder + "/" + data["logs_folder"].get<string>();
        // this->db_path = data["db_path"].get<string>();
        this->sleep_time = data["sleep_time"].get<string>();
        this->max_workers = data["max_workers"].get<string>();
    }
};

#endif // IPLUGIN_H