#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BST.h"

using namespace std;

void experimentGenerator(int x);
void smallShakeAndShuffle(BST &x, vector<int> &y);
void largeShakeAndShuffle(BST &x, vector<int> &y);
void outputTests(BST &x, vector<int> ai, vector<int> rie);

int main(){
    cout << "Round 1, 1000. Fight!" << endl;
    experimentGenerator(1000);
    cout << "------------------------------\n" << endl;
    
    cout << "Round 2, 10000. Fight!" << endl;
    experimentGenerator(10000);
    cout << "------------------------------\n" << endl;
    
    cout << "Round 3, 50000. Fight!" << endl;
    experimentGenerator(50000);
    cout << "------------------------------\n" << endl;


    // BST test = BST();
    // test.insert(5);
    // test.insert(2);
    // test.insert(7);
    // test.insert(1);
    // test.insert(3);

    // test.remove(1);
    // test.remove(2);
    // test.remove(5);
    // test.remove(7);
    // cout<<"HELLO"<<endl;
    // test.remove(3);
}

void experimentGenerator(int x){
    vector<int> inputVals = vector<int>(x);
    vector<int> inputValsSlightly = vector<int>(x);
    vector<int> inputValsVery = vector<int>(x);

    for(int i = 0; i < x; i++){
        inputVals.at(i) = i;
        inputValsSlightly.at(i) = i;
        inputValsVery.at(i) = i;
    }

    /*generate test cases*/
    int half = x / 2;
    int tenth = 50;
    if (half == 0){
        half = 1;
        tenth = 1;
    }
    vector<int> ai = vector<int>(half);
    vector<int> rie = vector<int>(tenth);
    for (int i = 0; i < half; i++){
        int mike = rand() % x;
        ai.at(i) = mike;
        // if (i % 5 == 0){
        //     rie.at(i / 5) = mike; 
        // }
    }
    for(int i = 0; i < 50; i++){
        int mike = rand() % x;
        rie.at(i) = mike;
    }

    BST* skewed = new BST();
    skewed->insertVector(inputVals);

    /*perform skewed tests here*/
    cout<<"Skewed"<<endl;
    outputTests(*skewed, ai, rie);
    cout<<"Height of Skewed: "<<skewed->getHeight()<<endl;
    cout<<"Average Depth of Skewed: "<<skewed->avgDepth()<<endl;

    /*-------------------------*/
    delete skewed;


    BST* slightlyRandom = new BST();
    smallShakeAndShuffle(*slightlyRandom, inputValsSlightly);
    slightlyRandom->insertVector(inputValsSlightly);

    /*perform slightly randomized tests here*/
    cout<<"Slightly Random"<<endl;
    outputTests(*slightlyRandom, ai, rie);
    cout<<"Height of Slightly Random: "<<slightlyRandom->getHeight()<<endl;
    cout<<"Average Depth of Slightly Random: "<<slightlyRandom->avgDepth()<<endl;

    /*-------------------------*/
    delete slightlyRandom;

    
    BST* veryRandom = new BST();
    largeShakeAndShuffle(*veryRandom, inputValsVery);
    veryRandom->insertVector(inputValsVery);
    /*perform slightly randomized tests here*/
    cout<<"Fully Random"<<endl;
    outputTests(*veryRandom, ai ,rie);
    cout<<"Height of Very Random: "<<veryRandom->getHeight()<<endl;
    cout<<"Average Depth of Very Random: "<<veryRandom->avgDepth()<<endl;

    /*-------------------------*/
    delete veryRandom;
}

void smallShakeAndShuffle(BST &x, vector<int> &y){
    int numberOfSwaps = 100;
    
    x.shuffle(y,numberOfSwaps/20);
    x.shake(y, numberOfSwaps, numberOfSwaps/2);
}

void largeShakeAndShuffle(BST &x, vector<int> &y){
    int numberOfSwaps = 100;//x.getNumNodes();
    
    x.shuffle(y, numberOfSwaps);
    x.shake(y, numberOfSwaps, numberOfSwaps);
}

void outputTests(BST &x, vector<int> ai, vector<int> rie){
    x.reset();
    int half = x.numNode / 2;
    int tenth = 50;
    if (half == 0){
        half = 1;
        tenth = 1;
    }
    //setup vectors
    int comps = 0;

    //find comparisons
    for (unsigned int y = 0; y < ai.size(); y++){
        x.find(ai.at(y));
    }
    comps = x.getCount() / half;
    cout << "Average comparisons for find: " << comps << endl;
    x.reset(); 

    //delete comparisons
    x.removeVector(rie);
    comps = x.getCount() / tenth;
    cout << "Average comparisons for remove: " << comps << endl;
    x.reset(); 

    //insert comparisons
    x.insertVector(rie);
    comps = x.getCount() / tenth;
    cout << "Average comparisons for insert: " << comps << endl;
    x.reset(); 
}