// Source : HackerEarth   

    string hashTable[21];
    int hashTableSize = 21;

// Insert

 void insert(string s)
    {
        //Compute the index using the hash function1
        int index = hashFunc1(s);
        int indexH = hashFunc2(s);
        //Search for an unused slot and if the index exceeds the hashTableSize roll back
        while(hashTable[index] != "")
            index = (index + indexH) % hashTableSize;
        hashTable[index] = s;
    }

// Search

  void search(string s)
    {
        //Compute the index using the hash function
        int index = hashFunc1(s);
        int indexH = hashFunc2(s);
         //Search for an unused slot and if the index exceeds the hashTableSize roll back
        while(hashTable[index] != s and hashTable[index] != "")
            index = (index + indexH) % hashTableSize;
        //Is the element present in the hash table
        if(hashTable[index] == s)
            cout << s << " is found!" << endl;
        else
            cout << s << " is not found!" << endl;
    }