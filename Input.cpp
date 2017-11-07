//
// Created by gusbr on 23/09/2017.
//

#include "Input.h"
#include <fstream>
#include "include/rapidjson/document.h"



void Input::getInp(char *input) {
    std::ifstream inFile;

    inFile.open(input);

    std::string inpString((std::istreambuf_iterator<char>(inFile)),
                          std::istreambuf_iterator<char>());

    const char* json = inpString.c_str();

    rapidjson::Document d;
    d.Parse(json);

    inFile.close();

    assert(d.IsObject());

    assert(d.HasMember("nServers"));
    assert(d["nServers"].IsInt());

    assert(d.HasMember("nSteps"));
    assert(d["nSteps"].IsInt());

    assert(d.HasMember("processCreationRate"));
    assert(d["processCreationRate"].IsInt());

    assert(d.HasMember("processDestructionRate"));
    assert(d["processDestructionRate"].IsInt());

    assert(d.HasMember("queueInitialLength"));
    assert(d["queueInitialLength"].IsInt());

    assert(d.HasMember("outputLevel"));
    assert(d["outputLevel"].IsInt());

    assert(d.HasMember("fastTrack"));
    assert(d["fastTrack"].IsBool());

    nServers = d["nServers"].GetInt();
    nQueues = nServers;
    nSteps = d["nSteps"].GetInt();
    processCreationRate = d["processCreationRate"].GetInt();
    processDestructionRate = d["processDestructionRate"].GetInt();
    queueInitialLength = d["queueInitialLength"].GetInt();
    outputLevel = d["outputLevel"].GetInt();
    fastTrack = d["fastTrack"].GetBool();

}

int Input::getNServers() {
    return nServers;
}

int Input::getNQueues() {
    return nQueues;
}

int Input::getNSteps() {
    return nSteps;
}

int Input::getProcessCreationRate() {
    return processCreationRate;
}

int Input::getProcessDestructionRate() {
    return processDestructionRate;
}

int Input::getOutputLevel() {
    return outputLevel;
}

int Input::getQueueInitialLength() {
    return queueInitialLength;
}

bool Input::getFastTrack() {
    return fastTrack;
}