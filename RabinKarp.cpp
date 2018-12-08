#include <iostream>
#include <math.h>

using namespace std;

int createHash(string x, int length){
    int hash = 0;
    int prime = 101;
    for(int i=0; i<=length; i++){
        hash += x[i]*pow(prime, i);
    }
    return hash;
}

int rollHash(string text, int old_ind, int new_ind, long old_hash, int patt_length){
    int prime = 101;
    //text[i] would print out to be the character at index i in text but when involved in arithmetic ops, text[i]
    //uses the corresponding ASCII value
    old_hash -= text[old_ind]; //old_ind==starting_ind(0) for the previous iteration and hence power would be 0, hence only need to subtract ASCII
    old_hash = old_hash/prime;
    int new_hash = old_hash + text[new_ind]*pow(prime, patt_length-1);
    return new_hash;

}

int rabinKarp(const string& t, const string& s){
    if(s.size()>t.size())
        return -1;
    int m = s.size();
    int n = t.size();
    long hash_s = createHash(s, s.size()-1);
    long hash_t = createHash(t, s.size()-1);

    //iteration starts at s.size() since hash already calculated till then
    for(int i=0; i<=t.size()-s.size(); ++i){
        if(hash_s==hash_t and !t.compare(i/*start_pos*/, s.size()/*noOfCharsFromStartPos*/, s))
            return i;

        //calculate rolling hash
        hash_t = rollHash(t, i-1, i+s.size()-1, hash_t, s.size());
        //Below is for the case when matching substring is the last substring in text ,eg "dcf" in "abcdcf".
        //We get rolling "hash_t" for dcf and since its the last iteration, the loop breaks to return -1 unless we
        //have a comparison as below
        if(hash_s==hash_t and !t.compare(i/*start_pos*/, s.size()/*noOfCharsFromStartPos*/, s))
            return i;
    }
    return -1;

}
