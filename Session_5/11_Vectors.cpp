#include<iostream>
#include<vector>


int main(){

#if 0
    std::vector<int> v1; // T-> int  ->  int* size = 0 capacity = 0 empty

    std::vector<int> v2(5);  // T-> int ->  int* size = 5 capacity = 8 init value 0

    std::vector<int> v3(5,10);  // T-> int ->  int* size = 5 capacity = 8 init value 10

    std::vector<int> v4{1,2,3,4,5};  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5

    std::vector<int> v5= v4;  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5

    std::vector<int> v6= (v5);  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5
    
    std::vector<int> v7= {v4};  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5

    int arr[] = {1,2,3,4,5};
    std::vector<int> v8(arr,arr+5);  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5

    std::vector<int> v9;  // T-> int ->  int* size = 5 capacity = 8 init value 1,2,3,4,5
    v9={1,2,3,4,5};

#endif

#if 0

    std::vector<int> v = {1,2,3,4,5};

    std::cout<<v.size()<<std::endl;
    std::cout<<v.capacity()<<std::endl;


    v.push_back(10);
    v.push_back(10);
    std::cout<<v.size()<<std::endl;
    std::cout<<v.capacity()<<std::endl;
    std::cout<<v.empty()<<std::endl;

#endif



#if 0
    std::vector<int> v;
    for(int i = 0; i < 100; i++){
        v.push_back(i);
        std::cout<<v.size()<<std::endl;
        std::cout<<v.capacity()<<std::endl;
        std::cout<<v.empty()<<std::endl;
    }

#endif

/* .resize() */

#if 0
    std::vector<int> v = {1,2,3,4,5,6};
    v.resize(3);
    std::cout<<v.size()<<std::endl;
    v.resize(7,100);
    std::cout<<v.size()<<std::endl;
    for(int i = 0; i < v.size(); i++){
        v.push_back(i);
        std::cout<<v.size()<<std::endl;
        std::cout<<v.capacity()<<std::endl;
        std::cout<<v.empty()<<std::endl;
    }
#endif

/* .size() & .capacity() */

#if 0
    std::vector<int> v;
    v.reserve(100);
    for(int i = 0; i < 10; i++){
        v.push_back(i);
        
    }
    std::cout<<v.size()<<std::endl;
    std::cout<<v.capacity()<<std::endl;
    v.shrink_to_fit();
    std::cout<<v.size()<<std::endl;
    std::cout<<v.capacity()<<std::endl;

#endif

/*push back and pop back*/

#if 0
    std::vector<int> v {1,2,3};
    v.push_back(4);
    std::vector<std::string> s;

    s.push_back("ahmed");

    v.pop_back();
    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
        
    }


#endif


/*insert*/
#if 0
    std::vector<int> v = {1,2,3,4};
    v.insert(v.begin()+1,6);

    for(int i = 0; i < v.size(); i++){
        std::cout<<i<<": "<<v[i]<<std::endl;
        
    }
    /*
        output:

        0: 1
        1: 6
        2: 2
        3: 3
        4: 4
    
    */
    v.insert(v.end(),{5,6,7,8});

    for(int i = 0; i < v.size(); i++){
        std::cout<<i<<": "<<v[i]<<std::endl;
        
    }
    /*
        output:
        
        0: 1
        1: 6
        2: 2
        3: 3
        4: 4
        5: 5
        6: 6
        7: 7
        8: 8
    
    */

    v.insert(v.end(),v.begin(),v.end());

    for(int i = 0; i < v.size(); i++){
        std::cout<<i<<": "<<v[i]<<std::endl;
        
    }



#endif


/*erase*/
#if 0
    std::vector<int> v {1,2,3};
    v.erase(v.begin()+2);

    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
        
    }

#endif

#if 0
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    v.erase(v.begin()+1, v.begin()+6);

    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
        
    }



#endif

/* emplace back */

#if 0
    std::vector<int> v {1,2,3};
    v.emplace_back(4);
    
    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
        
    }


#endif

/* logical operations */

#if 0
    std::vector<int> v1 {1,2,3,4};
    std::vector<int> v2 {1,2,3};

    bool x = v1 > v2;
    bool y = v1 == v2;



#endif

/*.at(index)*/
#if 0
    std::vector<int> v {1,2,3,4,5,6};

#endif

/* .data() */

#if 1
    std::vector<int> v {1,2,3};

    auto *ptr = v.data();

#endif

//


}