#include "MyHttpMethods.h"
#include <string>
#include <curl/curl.h>
MyHttpMethods::MyHttpMethods() {
    curl_global_init(CURL_GLOBAL_ALL);
}
MyHttpMethods::~MyHttpMethods() {
    curl_global_cleanup();
}
size_t writeCallback(char* dataBuffer, size_t size, size_t nmemb, string* userdata) {
    size_t dataSize = size * nmemb;
    userdata->append(dataBuffer, dataSize);
    return dataSize;
}
//get method
string MyHttpMethods::get(const string& url) {
    string response;
    CURL* curlHandle = curl_easy_init();
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT, 10L);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            response = "Error: " + string(curl_easy_strerror(res));
        }
        curl_easy_cleanup(curlHandle);
    } else {
        response = "Error: Failed to initialize libcurl";
    }
    return response;
}
//post method
string MyHttpMethods::post(const string& url, const string& data) {
    string response;
    CURL* curlHandle = curl_easy_init();
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT, 10L);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            response = "Error: " + string(curl_easy_strerror(res));
        }
        curl_easy_cleanup(curlHandle);
    } else {
        response = "Error: Failed to initialize libcurl";
    }
    return response;
}
//put method
string MyHttpMethods::put(const string& url, const string& data) {
    string response;
    CURL* curlHandle = curl_easy_init();
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT, 10L);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            response = "Error: " + string(curl_easy_strerror(res));
        }
        curl_easy_cleanup(curlHandle);
    } else {
        response = "Error: Failed to initialize libcurl";
    }
    return response;
}
//delete method
string MyHttpMethods::del(const string& url) {
    string response;
    CURL* curlHandle = curl_easy_init();
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curlHandle, CURLOPT_NOBODY, 1L); 
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT, 10L);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            response = "Error: " + string(curl_easy_strerror(res));
        }
        curl_easy_cleanup(curlHandle);
    } else {
        response = "Error: Failed to initialize libcurl";
    }
    return response;
}

