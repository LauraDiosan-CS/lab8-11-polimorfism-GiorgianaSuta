#include "test.h"
#include "testEntitate.h"
#include "TestService.h"

#include <iostream>
#include "service.h"
#include "UI.h"
using namespace std;


int main()
{
    testEntitate();
    TestRepoFile test;
    test.testAll();
    testService();
   
    cout << "Testele au avut SUCCES!!!!" << endl;
    //Service service;
   // UI u(service);
   // u.AdaugareUser();
   // u.showMenu();
}

