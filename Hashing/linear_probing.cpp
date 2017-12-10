 // Source :  HackerEarth

 string hashTable[21];
    int hashTableSize = 21;

// Insert

void insert(string s)
    {
        //Compute the index using the hash function
        int index = hashFunc(s);
        //Search for an unused slot and if the index will exceed the hashTableSize then roll back
        while(hashTable[index] != "")
            index = (index + 1) % hashTableSize;
        hashTable[index] = s;
    }

// Search

   void search(string s)
    {
        //Compute the index using the hash function
        int index = hashFunc(s);
         //Search for an unused slot and if the index will exceed the hashTableSize then roll back
        while(hashTable[index] != s and hashTable[index] != "")
            index = (index + 1) % hashTableSize;
        //Check if the element is present in the hash table
        if(hashTable[index] == s)
            cout << s << " is found!" << endl;
        else
            cout << s << " is not found!" << endl;
    }