#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
    const string fileNameInTXT = "testProduseIn.txt";
    const string fileNameOutTXT = "testProduseOut.txt";
    const string fileNameInCSV = "testProduseIn.csv";
    const string fileNameOutCSV = "testProduseOut.csv";

   
    vector<Entitate*> produseIn;

    void testGetSize();
    void testGetAll();
    void testGetProdus();
    void testAddProdus();
    void testUpdateProdus();
    void testDeleteProdus();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();
    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};