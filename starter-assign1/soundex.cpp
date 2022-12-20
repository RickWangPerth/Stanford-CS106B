/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <cctype>
#include <fstream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "vector.h"
#include "stdio.h"
#include "SimpleTest.h" // IWYU pragma: keep (needed to quiet spurious warning)
#include <map>
#include<list>
using namespace std;

map<string,string> encodeMap = {
    { "A", "0" },
    { "E", "0" },
    { "I", "0" },
    { "O", "0" },
    { "U", "0" },
    { "H", "0" },
    { "W", "0" },
    { "Y", "0" },
    { "B", "1" },
    { "F", "1" },
    { "P", "1" },
    { "V", "1" },
    { "C", "2" },
    { "G", "2" },
    { "J", "2" },
    { "K", "2" },
    { "Q", "2" },
    { "S", "2" },
    { "X", "2" },
    { "Z", "2" },
    { "D", "3" },
    { "T", "3" },
    { "L", "4" },
    { "M", "5" },
    { "N", "5" },
    { "R", "6" },
};


/* This function is intended to return a string which
 * includes only the letter characters from the original
 * (all non-letter characters are excluded)
 *
 * WARNING: The provided code is buggy!
 *
 * Bug: Input start with non-lettter
 */
string lettersOnly(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

string letterEncoder(string s){
    string upperS = toUpperCase(s);

//    string digit0 = "AEIOUHWY";
//    string digit1 = "BFPV";
//    string digit2 = "CGJKQSXZ";
//    string digit3 = "DT";
//    string digit4 = "L";
//    string digit5 = "MN";
//    string digit6 = "R";

    for (int i = 0; i < upperS.length(); i++) {
        for (const auto& [key, value] : encodeMap){
            if(key == charToString(upperS[i])){
                upperS.replace(i,1,value);
            }
        }
    }
    return upperS;
}


string duplicateRemover(string s){
    for (int i=s.size(); i>0; i--){
        if(s[i] == s[i-1]){
            s.erase(i,1);
        }
    }
    return s;
}


string zerosRemover(string s){
    for (int i=s.size(); i>0; i--){
        if(s[i] == '0'){
            s.erase(i,1);
        }
    }
    return s;
}

string sizeAdjuster(string s){
    if(s.size() != 4){
        int diff = 4 - s.size();
        if(diff < 0){
            s = s.substr(0,4);
        }else{
            for(int j=0; j<diff; j++){
                s = s.append("0");
            }
        }
    }
    return s;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    string letterS = lettersOnly(s);
    string originFirstChar =  charToString(toUpperCase(letterS[0]));
    string encoded = letterEncoder(letterS);
    string dupremoved = duplicateRemover(encoded);
    string firstCharConverted = dupremoved.replace(0,1,originFirstChar);
    string zeroRemoved = zerosRemover(firstCharConverted);
    string adjusted = sizeAdjuster(zeroRemoved);
    return adjusted;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // This provided code opens the specified file
    // and reads the lines into a vector of strings
    ifstream in;
    Vector<string> allNames;
    //vector<string> matchNames;
    if (openFile(in, filepath)) {
        readEntireFile(in, allNames);
    }
    cout << "Read file " << filepath << ", "
         << allNames.size() << " names found." << endl;

    // The names read from file are now stored in Vector allNames

    /* TODO: Fill in the remainder of this function. */
    allNames.sort();
    cout << "Enter a surname (RETURN to quit): ";
    string inputS;
    while(cin >> inputS){
        string nameCode = soundex(inputS);
        cout << "Soundex code is " << nameCode << endl;
        cin.ignore();
        cout << "Matches from database: {";
        for(auto name : allNames){
            if(soundex(name) == nameCode){
                cout << '"'<< name << "\",";
                //matchNames.emplace_back(name);
            }
        }
        //for(auto mn : matchNames){
            //cout << '"'<< mn << "\",";
        //}
        cout << '}' << endl;
        cout << "Enter a surname (RETURN to quit): ";
        if(cin.get() == '\n') break;
    }
    cout << "All done!" << endl;
}


/* * * * * * Test Cases * * * * * */


PROVIDED_TEST("Test exclude of punctuation, digits, and spaces") {
    string s = "O'Hara";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");
    s = "1Wang2";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Wang");
}


PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

// TODO: add your test cases here
STUDENT_TEST("letterEncoder Test: test the encoded output"){
    EXPECT_EQUAL(letterEncoder("Curie"), "20600");
    EXPECT_EQUAL(letterEncoder("Schwarz"), "2200062");
}

STUDENT_TEST("duplicateRemover Test: test the converted output"){
    EXPECT_EQUAL(duplicateRemover("20600"), "2060");
    EXPECT_EQUAL(duplicateRemover("2200062"), "2062");
}

STUDENT_TEST("zerosRemover Test: test the converted output"){
    EXPECT_EQUAL(zerosRemover("2060"), "26");
    EXPECT_EQUAL(zerosRemover("2062"), "262");
}
STUDENT_TEST("sizeAdjuster Test: test the converted output"){
    EXPECT_EQUAL(sizeAdjuster("C6"), "C600");
    EXPECT_EQUAL(sizeAdjuster("S62"), "S620");
    EXPECT_EQUAL(sizeAdjuster("A6212"), "A621");
}


