#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
    unsigned int d;
    d = barcode / 1000000 % 10;
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
    unsigned int d;
    d = barcode / 100000 % 10;
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
    unsigned int d;
    d = barcode / 10000 % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
    unsigned int d;
    d = barcode / 1000 % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    unsigned int d;
    d = barcode / 100 % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode) {
    unsigned int d;
    d = barcode / 10 % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode) {
    unsigned int d;
    d = barcode % 10;
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  Item glasses(itemColor,itemShape, itemBrand, barcode);
  hT1.insert({barcode, glasses});
  hT2.insert({barcode, glasses});
  hT3.insert({barcode, glasses});
  hT4.insert({barcode, glasses});
  hT5.insert({barcode, glasses});
  hT6.insert({barcode, glasses});
  hT7.insert({barcode, glasses});
  // for(unsigned int i=0; i < length; i++){
  //   allTables[i].insert({barcode,glasses});
  // }
}

bool ItemCollection::removeItem(unsigned int barcode) {
  if(hT1.find(barcode) == hT1.end()){ //if not found
    return false;
  } else {
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);
  }

    return true;
}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

    unsigned int balance[8];
    balance[0] = 0;

    unsigned int min_loc, max_loc;
    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT1.bucket_size(i);
        max_loc = hT1.bucket_size(i);
      } else {
        if(hT1.bucket_size(i) < min_loc){
          min_loc = hT1.bucket_size(i);
        }
        if(hT1.bucket_size(i) > max_loc){
          max_loc = hT1.bucket_size(i);
        }
      }
    }
    balance[1] = max_loc - min_loc;

    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT2.bucket_size(i);
        max_loc = hT2.bucket_size(i);
      } else {
        if(hT2.bucket_size(i) < min_loc){
          min_loc = hT2.bucket_size(i);
        }
        if(hT2.bucket_size(i) > max_loc){
          max_loc = hT2.bucket_size(i);
        }
      }
    }
    balance[2] = max_loc - min_loc;

    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT3.bucket_size(i);
        max_loc = hT3.bucket_size(i);
      } else {
        if(hT3.bucket_size(i) < min_loc){
          min_loc = hT3.bucket_size(i);
        }
        if(hT3.bucket_size(i) > max_loc){
          max_loc = hT3.bucket_size(i);
        }
      }
    }
    balance[3] = max_loc - min_loc;

    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT4.bucket_size(i);
        max_loc = hT4.bucket_size(i);
      } else {
        if(hT4.bucket_size(i) < min_loc){
          min_loc = hT4.bucket_size(i);
        }
        if(hT4.bucket_size(i) > max_loc){
          max_loc = hT4.bucket_size(i);
        }
      }
    }
    balance[4] = max_loc - min_loc;

    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT5.bucket_size(i);
        max_loc = hT5.bucket_size(i);
      } else {
        if(hT5.bucket_size(i) < min_loc){
          min_loc = hT5.bucket_size(i);
        }
        if(hT5.bucket_size(i) > max_loc){
          max_loc = hT5.bucket_size(i);
        }
      }
    }
    balance[5] = max_loc - min_loc;
    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT6.bucket_size(i);
        max_loc = hT6.bucket_size(i);
      } else {
        if(hT6.bucket_size(i) < min_loc){
          min_loc = hT6.bucket_size(i);
        }
        if(hT6.bucket_size(i) > max_loc){
          max_loc = hT6.bucket_size(i);
        }
      }
    }
    balance[6] = max_loc - min_loc;

    for(unsigned i=0; i < 10; i++){
      if(i == 0){
        min_loc = hT7.bucket_size(i);
        max_loc = hT7.bucket_size(i);
      } else {
        if(hT7.bucket_size(i) < min_loc){
          min_loc = hT7.bucket_size(i);
        }
        if(hT7.bucket_size(i) > max_loc){
          max_loc = hT7.bucket_size(i);
        }
      }
    }
    balance[7] = max_loc - min_loc;
    min_loc = balance[1];
    for(unsigned int i = 2; i < 8; i++){
      if(balance[i] < min_loc){
        min_loc = balance[i];
      }
    }
    cout << endl << min_loc << endl;
    return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
