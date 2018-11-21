////#include <memory>
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include "Header.h"
////
////using namespace std;
////
////const char infoStr [] = { "INFO: THIS EXAMPLE EXPLAINS HOW TO CREATE UNIQUE POINTER AND MANIPULATE THEM\n"};
////
//////*************************************************************************************************
////
////class TestData
////{
////public:
////  TestData( ) { m_p = new int(100); }
////  ~TestData( )
////  {
////    delete m_p;
////    cout<<" Destructor is called...."<<endl;
////  }
////  int* GetData( )
////  {
////    return m_p;
////  }
////  void Print( )
////  {
////    cout<<" Value = "<<*m_p<<endl;
////  }
////private:
////        int* m_p;
////};
////
//////*************************************************************************************************
////void Fun1( unique_ptr<int> up )
////{
////  cout<<" Value of up = "<<*up<<endl;
////}
////
//////*************************************************************************************************
////void Fun2( unique_ptr<int>& up )
////{
////  cout<<" Value of up = "<<*up<<endl;
////}
//////*************************************************************************************************
////template <class T>
////void Fun3( unique_ptr<T>& up )
////{
////  //After processing , say the pointer up is reset.
////  //reset calls the destructor of the resource
////  up.reset( );
////}
//////*************************************************************************************************
////
////void main()
////{
////  //1. Creating an unique pointer
////  //------------------------------------
////      unique_ptr<int> up1( new int(10) );
////      cout<<" Value of up1 = "<<*up1<<endl;
////
////  //2. Assigning the unique pointer is not allowed
////  //----------------------------------------------------------------
////      //unique_ptr<int> up2 = up1;
////
////  //3. Copy construction is not allowed. So cannot pass by value to a function
////  //------------------------------------------------------------------------------------------------------
////      //Fun1(up1);
////
////  //4. But can pass by reference
////  //----------------------------------
////      Fun2(up1);
////
////  //5. Getting raw pointer from the unique pointer
////  //--------------------------------------------------------
////      int* p = up1.get( );
////
////  //6. You can add the unique pointer to the vector
////  //----------------------------------------------------------
////      std::vector< unique_ptr<int> > vecUp;
////      //vecUp.push_back( up1 );             //Does not work as copy is not allowed
////      vecUp.push_back( std::move(up1) );      //Works fine as move is allowed
////      vecUp.push_back( unique_ptr<int>( new int(20) ));
////      vecUp.push_back( unique_ptr<int>( new int(30) ));
////
////      //After move up1 is no more valid as it has transferred
////      //the owneship to the element in the vector vecUp.
////      if( up1 )
////      {
////        cout<<"up1 is still valid...."<<endl;
////      }
////      else
////      {
////        cout<<"up1 is no more valid...."<<endl;
////      }
////
////      for_each( vecUp.begin(), vecUp.end(),[ ](unique_ptr<int>& p)
////      {
////        cout<<*p<<" ";
////      });
////
////
////  //LEAKING ALIASES FROM UNIQUE POINTER
////  //7. Be careful with constructing unique pointers from aliases
////  //------------------------------------------------------------------------
////      int* ip = new int(50);
////      std::unique_ptr<int> up3(ip);
////
////      //Resource of up3 is now moved to the argument to the function. So up3 is no more
////      //valid. Accessing up3 further crashes the program
////      Fun1( std::move(up3) );
////      vecUp.push_back( std::move(up3));
////
////      //At the end of Fun1, argument goes out of scope and the destructor for the resource is called.
////      //The pointer is no more valid. So the below call prints garbage value
////      cout<<" Value of ip = "<<*ip<<endl;
////
////  //8. Unique Ptrs has backdoor to get the pointer. If the pointers go dangling when the unique
////  //pointers goes out of scope, it causes crash.
////  //-----------------------------------------------------------------------------------------------------------------
////      TestData* pTD = NULL;
////      {
////        std::unique_ptr<TestData> up4( new TestData );
////        pTD = up4.get( );
////        pTD->Print( );
////      }
////      //The following call is going to crash as alreadh the destructor of the resource of the unique pointer
////      //is called
////      //pTD->Print( );
////
////  //9. Be careful while getting reference to the member of the resource held by unique pointer
////  //------------------------------------------------------------------------------------------------------------
////      std::unique_ptr<TestData> up5( new TestData);
////
////      //Get the reference to the member of up5
////      int* ipRes = up5->GetData( );
////
////      //After processing up5 is released
////      Fun3<TestData>(up5);
////
////      //Accessing ipRes is no more valid as the function argument is destroyed at the end of the function
////      cout<<" Value of ipRes = "<<*ipRes<<endl;
////
////  //10. Assigning unique pointers release previously owned resource
////  //--------------------------------------------------------------------------------------------
////      std::unique_ptr<TestData> up6( new TestData );
////      std::unique_ptr<TestData> up7( new TestData );
////
////      //Calls the destructor for the resource owned by up6, before owning
////      //the new resource from up7
////      up6 = std::move( up7 );
////
////}
//
//
//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//int main()
//{
//	//shared_ptr<int> sp1= make_shared<int>(100);
//	shared_ptr<int> sp1 (new int[10]);
//
//return 0;
//}

//#include<iostream>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//int main() {
//
//	// Creating an Unoredered_set of type string
//	std::unordered_set<std::string> setOfStrs;
//
//	// Insert strings to the set
//	setOfStrs.insert("First");
//	setOfStrs.insert("second");
//	setOfStrs.insert("third");
//
//	// Try to Insert a duplicate string in set
//	setOfStrs.insert("second");
//
//	// Iterate Over the Unordered Set and display it
//	for (std::string s : setOfStrs)
//		std::cout<< s << std::endl;
//
//}


//#include <iostream>
//#include <set>
//#include <string>
//#include <algorithm>
//
//
///*
// * Access nth element from a set.
// * It returns a pair of Element and bool.
// * bool represents if nth element exists in set or not.
// * if bool is true them First element of pair T contains the element value
// */
//template <typename T>
//std::pair<T, bool> getNthElement(std::set<T> & searchSet, int n)
//{
//	std::pair<T, bool> result;
//	if(searchSet.size() > n )
//	{
//		result.first = *(std::next(searchSet.begin(), n));
//		result.second = true;
//	}
//	else
//		result.second = false;
//
//	return result;
//}
//
//int main()
//{
//	std::set<std::string> setOfStr =
//				{ "bb", "ee", "dd", "aa", "ll" };
//
//	std::cout<<"***** Set Contents *****"<<std::endl;
//	for(std::string elem : setOfStr)
//		std::cout<<elem<<std::endl;
//
//	std::cout<<"***** Accessing Elements by Index ***"<<std::endl;
//
//	// Access 3rd element
//	std::pair<std::string, bool> result = getNthElement(setOfStr, 3);
//
//	if(result.second)
//		std::cout<<"3rd Element in set = "<<result.first<<std::endl;
//	else
//		std::cout<<"3rd Element in set not found"<<std::endl;
//
//
//	// Access 7th element
//	result = getNthElement(setOfStr, 7);
//
//	if(result.second)
//		std::cout<<"7th Element in set = "<<result.first<<std::endl;
//	else
//		std::cout<<"7th Element in set not found"<<std::endl;
//
//}

//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Show()
//	{
//		std::cout<<"Base Method"<<endl;
//
//	}
//};
//class Derived : public Base
//{
//public:
//	void Show()
//	{
//		cout<<"Dervived Method"<<endl;
//	}
//};
//
//int main()
//{
//	Base *b = new Derived;
//	Derived *d = dynamic_cast<Derived*> (b);
//	d->Show();
//	b->Show();
//	if(d!= NULL)
//	{
//		cout<<"Dynamic Cast Success"<<endl;
//	}
//	else
//	{
//		cout<<"Dynamic Cast Fail"<<endl;
//	}
//
//	return 0;
//
//}

// A C++ program uses transform() in STL to add
// 1 to all elements of arr[]
//#include <iostream>
//using namespace std;
//
//int increment(int x) {  return (x+1); }
//
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5};
//    int n = sizeof(arr)/sizeof(arr[0]);
//
//    // Apply increment to all elements of
//    // arr[] and store the modified elements
//    // back in arr[]
//    transform(arr, arr+n, arr, increment);
//
//    for (int i=0; i<n; i++)
//        cout << arr[i] << S" ";
//
//    return 0;
//}

//#include <iostream>
//#include <memory>
//
//typedef struct Sample {
//	Sample(){
//		std::cout<<"CONSTRUCTOR\n";
//	}
//	~Sample(){
//		std::cout<<"DESTRUCTOR\n";
//	}
//}Sample;
//
//void deleter (Sample * x) {
//	std::cout<<"DELETER FUNCTION CALLED\n";
//	delete[] x;
//}
//
//int main()
//{
//	std::shared_ptr<Sample> p3(new Sample[12], deleter);
//
//	return 0;
//}

//#include<iostream>
//#include<memory>
////typedef struct Sample {
////Sample() {
////  //internalValue = 0;
////  std::cout<<"Constructor"<<std::endl;
////}
////~Sample() {
////  std::cout<<"Destructor"<<std::endl;
////}
////};
//int main()
//{
//	//Sample * rawPtr = new Sample();
//	//std::shared_ptr<Sample> ptr_1(rawPtr);
//	//std::shared_ptr<Sample> ptr_2(rawPtr);
//	int x = 12;
//	std::shared_ptr<int>ptr(&x);
//
//// As ptr_2 dont know that the same raw pointer is used by another shared_ptr i.e. ptr_1, therefore
//// here when ptr_2 goes out of scope and it deletes the raw pointer associated with it.
//
//// Now ptr_1 is internally containing a dangling pointer. Therefore when we it
//// will go out of scope it will again try to delete the already deleted raw pointer and application
//// will crash.
//
//return 0;
//}

//#include <iostream>
//
//#include <memory>
//
//class Node
//
//{
//    int value;
//    public:
//    std::shared_ptr<Node> leftPtr;
//    std::shared_ptr<Node> rightPtr;
//	std::shared_ptr<Node> parentPtr;
//    Node(int val) : value(val) {
//         std::cout<<"Contructor"<<std::endl;
//    }
//    ~Node() {
//         std::cout<<"Destructor"<<std::endl;
//    }
//};
//int main()
//{
//    /*std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
//    ptr->leftPtr = std::make_shared<Node>(2);
//    ptr->leftPtr->parentPtr = ptr;
//    ptr->rightPtr = std::make_shared<Node>(5);
//    ptr->rightPtr->parentPtr = ptr;
//    std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;
//    std::cout<<"ptr->leftPtr reference count = "<<ptr->leftPtr.use_count()<<std::endl;
//    std::cout<<"ptr->rightPtr reference count = "<<ptr->rightPtr.use_count()<<std::endl;*/
//
//	 std::shared_ptr<int> ptr = std::make_shared<int>(4);
//    std::weak_ptr<int> weakPtr(ptr);
//    std::shared_ptr<int> ptr_2 =  weakPtr.lock();
//    if(ptr_2)
//        std::cout<<(*ptr_2)<<std::endl;
//    std::cout<<"Reference Count :: "<<ptr_2.use_count()<<std::endl;
//    if(weakPtr.expired() == false)
//        std::cout<<"Not expired yet"<<std::endl;
//    return 0;
//    return 0;
//}

//#include <iostream>
//#include <list>
//#include<vector>
//#include<deque>
//#include<set>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	// Create a list and initialize it with 5 elements of value 119
//	std::list<int> listOfInts(5, 119);
//	vector<int>vect(5,25);
//	deque<int>dq(10,9);
//	//set<int>myset(15,5);
//
//	// Iterate over the list and display numbers
//	for (int val : listOfInts)
//		std::cout << val << ",";
//	std::cout << std::endl;
//
//	for(int val1 : vect)
//	cout << val1 << ",";
//	cout<<endl;
//
//	for(int val2 : dq)
//	cout << val2 << ",";
//	cout<<endl;
//
//	priority_queue<int>pq;
//
//	pq.push(1);
//	pq.push(50);
//	pq.push(3);
//	pq.push(2);
//	pq.push(6);
//
//	while(!pq.empty())
//	{
//		cout<<pq.top()<<",";
//		pq.pop();
//	}
//	cout<<endl;
//
//	/*for(int val3 : myset)
//	cout << val3 << ",";
//	cout<<endl;*/
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	vector<int>vect;
//
//	vect.push_back(23);
//	vect.push_back(3);
//	vect.push_back(56);
//	vect.push_back(700);
//	vect.push_back(1);
//	vect.push_back(34);
//
//	cout<<"*** Element Before Sort ***"<<endl;
//	for(int val : vect)
//		cout<<val<<" ";
//		cout<<endl;
//
//	sort(vect.begin(),vect.end());
//	cout<<"*** Element After Sort ***"<<endl;
//	for(int val1 : vect)
//		cout<<val1<<" ";
//	cout<<endl;
//
//	if(binary_search(vect.begin(),vect.end(),700))
//		cout<<"No. Found"<<endl;
//	else
//		cout<<"No. Not Found"<<endl;
//
//	return 0;
//}


//#include <iostream>
//#include <list>
//#include <list>
//
//int main() {
//	// Create a list and initialize it initializer_list of 7 elements
//	std::list<int> listOfInts( { 2, 8, 7, 5, 3, 1, 4 });
//
//	// Iterate over the list and display numbers
//	for (int val : listOfInts)
//		std::cout << val << ",";
//	std::cout << std::endl;
//
//	// Create a initializer list of strings
//	std::initializer_list<std::string> initLits =
//			{ "Hi", "this", "is", "sample" };
//
//	// Create & Initialize a list with initializer_list object
//	std::list<std::string> listOfStrs(initLits);
//
//	// Iterate over the list and display strings
//	for (std::string data : listOfStrs)
//		std::cout << data << std::endl;
//
//	return 0;
//}


//#include <iostream>
//#include <unordered_set>
//#include <algorithm>
//#include <vector>
//
//int main() {
//
//	// Array of int
//	int arr[] = { 2, 4, 6, 1, 3, 6, 8, 3, 2 };
//
//	// Create an unoredered set and initialize it with the array
//	// Set will contain only unique elements
//	std::unordered_set<int> setOfNum(arr, arr + sizeof(arr) / sizeof(int));
//
//	// Iterate over the set and display contents
//	for (int val : setOfNum)
//		std::cout << val << "  ";
//	std::cout << std::endl;
//
//	// Create an unoredered set and initialize it initializer_list
//	std::unordered_set<int> setOfNum2( { 1, 2, 3, 1, 3, 4, 2 });
//
//	// Set will contain only unique elements
//	// Iterate over the set and display contents
//	for (int val : setOfNum2)
//		std::cout << val << "  ";
//	std::cout << std::endl;
//
//	std::vector<int> vec( { 14, 5, 6, 7 });
//	// Create an unoredered set and initialize it with vector
//	std::unordered_set<int> setOfNum3(vec.begin(), vec.end());
//
//	// Set will contain only unique elements
//	// Iterate over the set and display contents
//	for (int val : setOfNum3)
//		std::cout << val << "  ";
//	std::cout << std::endl;
//
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	vector<int>vect;
//	vect.push_back(1);
//	vect.push_back(2);
//	vect.push_back(2);
//	vect.push_back(3);
//	vect.push_back(1);
//	vect.push_back(4);
//	vect.push_back(5);
//	vect.push_back(4);
//	vect.push_back(6);
//	vect.push_back(3);
//	vect.push_back(9);
//
//	for(int val :vect)
//		cout<<val;
//	cout<<endl;
//	sort(vect.begin(),vect.end());
//
//	for(int val1 :vect)
//	cout<<val1;
//	cout<<endl;
//
//	std::vector<int>::iterator newEnd;
//	newEnd = unique(vect.begin(),vect.end());
//	vect.erase(newEnd, vect.end());
//
//	for(int val2 :vect)
//	cout<<val2;
//	cout<<endl;
//
//
//
//
//return 0;
//}

//#include <iostream>
//#include <string>
//
//void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
//{
//	// Get the first occurrence
//	size_t pos = data.find(toSearch);
//
//	// Repeat till end is reached
//	while( pos != std::string::npos)
//	{
//		// Replace this occurrence of Sub String
//		data.replace(pos, toSearch.size(), replaceStr);
//		// Get the next occurrence from the current position
//		pos =data.find(toSearch, pos + toSearch.size());
//	}
//}
//
//int main()
//{
//	std::string data = "Boost Library is simple C++ Library";
//
//	std::cout<<data<<std::endl;
//
//	findAndReplaceAll(data, "Lib", "C");
//
//	std::cout<<data<<std::endl;
//
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//using namespace stdext;
//
//int main()
//{
//	string str = "allow is allow";
//	cout<<str<<endl;
//
//
//	return 0;
//}

//#include<iostream>
//#include<unordered_map>
//#include<string>
//using namespace std;
//
//int main()
//{
//	unordered_map<string,int>mymap;
//
//	mymap.insert(pair<string,int>("First",10));
//	mymap.insert(pair<string,int>("Second",20));
//	mymap.insert(pair<string,int>("Third",30));
//	mymap.insert(pair<string,int>("Fourth",40));
//	mymap.insert(pair<string,int>("Fifth",50));
//	mymap.insert(pair<string,int>("Sixth",60));
//
//	cout<<"Initial List"<<endl;
//	unordered_map<string,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//
//	}
//
//	unordered_map<string,int>::iterator itr = mymap.begin();
//
//	while(itr != mymap.end())
//	{
//		if(itr->first[0] == 'F')
//		{
//			itr = mymap.erase(itr);
//		}
//		else
//		itr++;
//
//	}
//	cout<<"After Erase"<<endl;
//	for(auto val : mymap)
//		cout<<val.first<<" "<<val.second<<endl;
//
//
//return 0;
//}


//#include<iostream>
//#include<thread>
//#include <condition_variable>
//#include<mutex>
//
//using namespace std;
//class Application
//{
// std::mutex m_mutex;
// bool m_bDataLoaded;
//public:
// Application()
// {
//// m_bDataLoaded = false;
// }
// void loadData()
// {
// // Make This Thread sleep for 1 Second
// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
// std::cout<<"Loading Data from XML"<<std::endl;
// for(int i=0;i<5;i++)
//	 cout<<"num"<<endl;
//
//
// // Lock The Data structure
// std::lock_guard<std::mutex> guard(m_mutex);
//
// // Set the flag to true, means data is loaded
// m_bDataLoaded = true;
//
// }
// void mainTask()
// {
// std::cout<<"Do Some Handshaking"<<std::endl;
//  for(int i=0;i<5;i++)
//	 cout<<"Char"<<endl;
//
// // Acquire the Lock
// m_mutex.lock();
// // Check if flag is set to true or not
// while(m_bDataLoaded != true)
// {
//  // Release the lock
//  m_mutex.unlock();
//  //sleep for 100 milli seconds
//  std::this_thread::sleep_for(std::chrono::milliseconds(100));
//  // Acquire the lock
//  m_mutex.lock();
//  }
//  // Release the lock
//  m_mutex.unlock();
//  //Doc processing on loaded Data
//  std::cout<<"Do Processing On loaded Data"<<std::endl;
// }
//};
//
//int main()
//{
//  Application app;
//
//  std::thread thread_1(&Application::mainTask, &app);
//  std::thread thread_2(&Application::loadData, &app);
//
//  thread_2.join();
//  thread_1.join();
//  return 0;
//}

//
//#include <iostream>
//#include <thread>
//#include <functional>
//#include <mutex>
//#include <condition_variable>
//using namespace std::placeholders;
//class Application
//{
//  std::mutex m_mutex;
//  std::condition_variable m_condVar;
//  bool m_bDataLoaded;
//public:
//  Application()
//  {
//    m_bDataLoaded = false;
//  }
//  void loadData()
//  {
//   // Make This Thread sleep for 1 Second
//   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//   std::cout<<"Loading Data from XML"<<std::endl;
//   // Lock The Data structure
//   std::lock_guard<std::mutex> guard(m_mutex);
//   // Set the flag to true, means data is loaded
//   m_bDataLoaded = true;
//   // Notify the condition variable
//   m_condVar.notify_one();
//  }
//  bool isDataLoaded()
//  {
//    return m_bDataLoaded;
//  }
//  void mainTask()
//  {
//    std::cout<<"Do Some Handshaking"<<std::endl;
//    // Acquire the lock
//    std::unique_lock<std::mutex> mlock(m_mutex);
//    // Start waiting for the Condition Variable to get signaled
//    // Wait() will internally release the lock and make the thread to block
//    // As soon as condition variable get signaled, resume the thread and
//    // again acquire the lock. Then check if condition is met or not
//    // If condition is met then continue else again go in wait.
//    m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
//    std::cout<<"Do Processing On loaded Data"<<std::endl;
//  }
//};
//int main()
//{
//   Application app;
//   std::thread thread_1(&Application::mainTask, &app);
//   std::thread thread_2(&Application::loadData, &app);
//   thread_2.join();
//   thread_1.join();
//   return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <memory>
//#include <string>
//#include <algorithm>
//#include <functional>
//
//class Item
//{
//private:
//    std::string  m_ItemId;
//    int m_Price;
//    int m_Count;
//public:
//    Item(std::string id, int price, int count):
//        m_ItemId(id), m_Count(count), m_Price(price)
//    {}
//    int getCount() const {
//        return m_Count;
//    }
//    std::string getItemId() const {
//        return m_ItemId;
//    }
//    int getPrice() const {
//        return m_Price;
//    }
//    bool operator==(const Item & obj2) const
//    {
//        if(this->getItemId().compare(obj2.getItemId()) == 0)
//            return true;
//        else
//            return false;
//    }
//};
//
//
//std::vector<Item> getItemList()
//{
//    std::vector<Item> vecOfItems ;
//    vecOfItems.push_back(Item("D121",100,2));
//    vecOfItems.push_back(Item("D122",12,5));
//    vecOfItems.push_back(Item("D123",28,6));
//    vecOfItems.push_back(Item("D124",8,10));
//    vecOfItems.push_back(Item("D125",99,3));
//    return vecOfItems;
//}
//
//bool priceComparision(Item & obj, int y)
//{
//    if(obj.getPrice() == y)
//        return true;
//    else
//        return false;
//}
//
//
//template <typename T>
//struct GenericComparator
//{
//    typedef  int (T::*GETTER)() const;
//    GETTER m_getterFunc;
//    int m_data;
//    GenericComparator(GETTER getterFunc, int data)
//    {
//        m_getterFunc = getterFunc;
//        m_data = data;
//    }
//    bool operator()(const Item  & obj)
//    {
//        if((obj.*m_getterFunc)() == m_data)
//            return true;
//        else
//            return false;
//    }
//};
//
//
//bool IsLesser10 (int i) {
//  return (i < 10);
//}
//
//int main()
//{
//
//    std::vector<int> vecData{1,2,3,4,5};
//
//    std::vector<int>::iterator it1;
//    it1 = std::find(vecData.begin(), vecData.end(), 2);
//    if(it1 != vecData.end())
//        std::cout<<*it1<<std::endl;
//    it1 = std::find_if(vecData.begin(), vecData.end(), IsLesser10 );
//    if(it1 != vecData.end())
//        std::cout<<*it1<<std::endl;
//
//
//    std::vector<Item> vecOfItems = getItemList();
//    std::vector<Item>::iterator it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D126",99,0));
//
//    if(it != vecOfItems.end())
//        std::cout<<"Found with ID :: "<<it->getItemId()<< " Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
//    else
//        std::cout<<"Item with ID :: D126 not Found"<<std::endl;
//
//    it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D124",99,0));
//    if(it != vecOfItems.end())
//        std::cout<<"Found with ID :: "<<it->getItemId()<< " Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
//    else
//        std::cout<<"Item with ID :: D124 not Found"<<std::endl;
//
//
//
//    it = std::find_if(vecOfItems.begin(), vecOfItems.end(), [](Item const& obj){
//                                                                            return obj.getPrice() == 28;
//                                                                        } );
//
//    if(it != vecOfItems.end())
//        std::cout<<"Found with ID :: "<<it->getItemId()<< " Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
//    else
//        std::cout<<"Item not Found"<<std::endl;
//
//
//
//        it = std::find_if(vecOfItems.begin(), vecOfItems.end(), std::bind(priceComparision,  std::placeholders::_1 , 28) );
//        if(it != vecOfItems.end())
//            std::cout<<"Found with ID :: "<<it->getItemId()<< " Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
//        else
//            std::cout<<"Item not Found"<<std::endl;
//
//
//
//    it = std::find_if(vecOfItems.begin(), vecOfItems.end(),  GenericComparator<Item>(&Item::getPrice, 99)   );
//    if(it != vecOfItems.end())
//        std::cout<<"Found with ID :: "<<it->getItemId()<< " Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
//    else
//        std::cout<<"Item not Found"<<std::endl;
//
//
//    return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int>vect;
//	vect.push_back(1);
//	vect.push_back(2);
//	vect.push_back(3);
//	vect.push_back(4);
//	vect.push_back(5);
//	vect.push_back(6);
//	vect.push_back(7);
//	vect.push_back(8);
//
//	for (int val : vect)
//		std::cout << val << " ";
//	cout<<endl;
//
//	/*vect.assign(7,100);
//
//	for(int val1 : vect)
//		cout<<val1<<" ";
//	cout<<endl;
//
//	vect.push_back(1);
//	vect.push_back(2);*/
//
//	int num = vect.at(5);
//	cout<<"num == "<<num<<endl;
//
//	cout<<"Vector Capacity == "<<vect.capacity()<<endl;
//	cout<<"vector MaxSize == "<<vect.max_size()<<endl;
//	vect.reserve(100);
//	cout<<"Vector Capacity == "<<vect.capacity()<<endl;
//
//	int *p = vect.data();
//
//	cout<<" p = "<<p<<endl;
//
//	vect.emplace(vect.end(),200);
//	vect.emplace_back(300);
//
//	for(int tmp : vect)
//		cout<<tmp<<" ";
//	cout<<endl;
//	int n = vect.size();
//	if( n == 0)
//		cout<<"vect is empty"<<endl;
//	else
//		cout<<"vect is not empty"<<endl;
//	vect.erase(vect.begin());
//	vect.erase(vect.end()-1);
//
//	for(int a : vect)
//		cout<<a<<" ";
//	cout<<endl;
//
//	cout<<"front == "<<vect.front()<<endl;
//
//	std::vector<int> myvector;
//  int * pt;
//  unsigned int i;
//
//  // allocate an array with space for 5 elements using vector's allocator:
//  pt = myvector.get_allocator().allocate(5);
//
//  // construct values in-place on the array:
//  for (i=0; i<5; i++) myvector.get_allocator().construct(&pt[i],i);
//
//  std::cout << "The allocated array contains:";
//  for (i=0; i<5; i++) std::cout << ' ' << pt[i];
//  std::cout << '\n';
//
//  // destroy and deallocate:
//  for (i=0; i<5; i++) myvector.get_allocator().destroy(&pt[i]);
//  myvector.get_allocator().deallocate(pt,5);
//
//  vect.insert(vect.end(),2,40);
//  vect.insert(vect.begin(),3,70);
//
//  for(int b : vect)
//	  cout<<b<<" ";
//  cout<<endl;
//
//  //vector<int>vect1;
//  //vect1 = vect;
//
//  //for(int c : vect1)
//	 // cout<<c<<" ";
//  //cout<<endl;
//  cout<<"Operator == "<<vect[1];
//  cout<<"Operator == "<<vect[6];
// // cout<<"Operator == "<<vect[100];
//  cout<<endl;
//
//  vect.resize(5);
//  for(int e : vect)
//	  cout<<e<<" ";
//  cout<<endl;
//
//  cout<<"capacity == "<<vect.capacity()<<endl;
//  vect.shrink_to_fit();
//  cout<<"capacity == "<<vect.capacity()<<endl;
//
//  std::vector<int> foo (3,100);   // three ints with a value of 100
//  std::vector<int> bar (5,200);   // five ints with a value of 200
//
//  //foo.swap(bar);
//  bar.swap(foo);
//
//  std::cout << "foo contains:";
//  for (unsigned i=0; i<foo.size(); i++)
//    std::cout << ' ' << foo[i];
//  std::cout << '\n';
//
//  std::cout << "bar contains:";
//  for (unsigned i=0; i<bar.size(); i++)
//    std::cout << ' ' << bar[i];
//  std::cout << '\n';
//
//
//	cout<<endl;
//  return 0;
//
//}


//#include<iostream>
//#include<list>
//
//using namespace std;
//
//int main()
//{
//	list<int>mylist;
//
//	mylist.push_back(1);
//	mylist.push_back(3);
//	mylist.push_back(5);
//	mylist.push_back(8);
//	mylist.push_front(2);
//	mylist.push_front(9);
//
//	list<int>::iterator it = mylist.begin();
//	while(it != mylist.end())
//	{
//		cout<<*it<<" ";
//		it++;
//
//	}
//
//	cout<<endl;
//
//	/*mylist.assign(7,100);
//
//	for(int a : mylist)
//		cout<<a<<" ";
//	cout<<endl;*/
//
//	mylist.emplace(mylist.begin(),100);
//	mylist.emplace_back(201);
//	mylist.emplace_front(23);
//
//	for(auto itr = mylist.cbegin(); itr!= mylist.cend();itr++)
//	{
//		cout<<*itr<<" ";
//
//	}
//	cout<<endl;
//
//	mylist.erase(mylist.begin());
//
//	for(auto b : mylist)
//		cout<<b<<" ";
//	cout<<endl;
//
//	cout<<"front == "<<mylist.front()<<endl;
//
//
//	//std::list<int> mylist1;
// // int * p;
//
// // // allocate an array of 5 elements using mylist's allocator:
// // p=mylist1.get_allocator().allocate(5);
//
// // // assign some values to array
// // for (int i=0; i<5; ++i) p[i]=i;
//
// // std::cout << "The allocated array contains:";
// // for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
// // std::cout << '\n';
//
// // mylist1.get_allocator().deallocate(p,5);
//
//	mylist.insert(mylist.begin(),344);
//	mylist.insert(mylist.end(),76);
//	for(int c: mylist)
//		cout<<c<<" ";
//	cout<<endl;
//
//	mylist.sort();
//
//	for(int d : mylist)
//		cout<<d<<" ";
//	cout<<endl;
//
//	list<int>tmplist;
//	tmplist.push_back(20);
//	tmplist.push_back(2);
//	tmplist.push_back(8);
//	tmplist.push_back(1);
//	tmplist.push_front(2);
//	tmplist.push_front(4);
//
//	tmplist.sort();
//
//	for(int e : tmplist)
//		cout<<e<<" ";
//	cout<<endl;
//
//	/*mylist.merge(tmplist);
//
//	for(int f: mylist)
//		cout<<f<<" ";
//	cout<<endl;
//
//	tmplist.merge(mylist);
//
//	for(int g : tmplist)
//		cout<<g<<" ";
//	cout<<endl;*/
//	/*cout<<"New List"<<endl;
//	list<int>l1;
//
//	l1 = mylist;
//	for(int h: l1)
//		cout<<h<<" ";
//	cout<<endl;
//*/
//	cout<<"*********"<<endl;
//	//mylist.remove(mylist.end());
//	mylist.remove_if([](const int &val )
//	{
//		if(val > 100)
//			return true;
//		else
//		return false;
//	});
//
//	for(int j : mylist)
//		cout<<j<<" ";
//	cout<<endl;
//
//	mylist.remove(100);
//
//	for(int k : mylist)
//		cout<<k<<" ";
//	cout<<endl;
//
//	mylist.reverse();
//
//	for(int l : mylist)
//		cout<<l<<" ";
//	cout<<endl;
//
//
//	//list<int>demolist;
//
//	////demolist.splice(mylist.begin(),mylist.end(),demolist);
//	//std::list<int> mylist1, mylist2;
// // std::list<int>::iterator itt;
//
// // // set some initial values:
// // for (int i=1; i<=4; ++i)
// //    mylist1.push_back(i);      // mylist1: 1 2 3 4
//
// // for (int i=1; i<=3; ++i)
// //    mylist2.push_back(i*10);   // mylist2: 10 20 30
//
// // itt = mylist1.begin();
// // ++itt;                         // points to 2
//
// // mylist1.splice (itt, mylist2); // mylist1: 1 10 20 30 2 3 4
// //                               // mylist2 (empty)
// //                               // "it" still points to 2 (the 5th element)
// //
// // mylist2.splice (mylist2.begin(),mylist1, itt);
// //                               // mylist1: 1 10 20 30 3 4
// //                               // mylist2: 2
// //                               // "it" is now invalid.
// // itt = mylist1.begin();
// // std::advance(itt,3);           // "it" points now to 30
//
// // mylist1.splice ( mylist1.begin(), mylist1, itt, mylist1.end());
// //                               // mylist1: 30 3 4 1 10 20
//
// // std::cout << "mylist1 contains:";
// // for (itt=mylist1.begin(); itt!=mylist1.end(); ++itt)
// //   std::cout << ' ' << *itt;
// // std::cout << '\n';
//
// // std::cout << "mylist2 contains:";
// // for (itt=mylist2.begin(); it!=mylist2.end(); ++itt)
// //   std::cout << ' ' << *itt;
// // std::cout << '\n';
//
//	mylist.push_back(1);
//	mylist.push_back(2);
//	mylist.push_back(98);
//	mylist.push_back(4);
//
//	for(int m : mylist)
//		cout<<m<<" ";
//	cout<<endl;
//
//	mylist.unique();
//
//
//	for(int n : mylist)
//		cout<<n<<" ";
//	cout<<endl;
//
//	mylist.unique();
//
//	for(int o : mylist)
//		cout<<o<<" ";
//	cout<<endl;
//
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<forward_list>
//using namespace std;
//
//int main()
//{
//	forward_list<int>flist;
//
//	flist.push_front(2);
//	flist.push_front(4);
//	flist.push_front(1);
//	flist.push_front(9);
//	flist.push_front(27);
//
//	for(int a: flist)
//		cout<<a<<" ";
//	cout<<endl;
//
//	/*flist.assign(7,100);
//	for(int b : flist)
//		cout<<b<<" ";
//	cout<<endl;*/
//
//	flist.insert_after ( flist.before_begin(), 11 );
//
//	std::cout << "mylist contains:";
//	for ( int& x: flist ) std::cout << ' ' << x;
//	std::cout << '\n';
//
//	flist.emplace_after(flist.begin(),200);
//	flist.emplace_front(flist.end(),35);
//	//flist.emplace_after(flist.end(),22);
//
//	for(int b : flist)
//		cout<<b<<" ";
//	cout<<endl;
//
//	flist.erase_after(flist.begin());
//
//	for(int c: flist)
//		cout<<c<<" ";
//	cout<<endl;
//
//
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int  main()
//{
//	set<int>myset;
//
//	myset.insert(5);
//	myset.insert(2);
//	myset.insert(6);
//	myset.insert(1);
//	myset.insert(3);
//	myset.insert(8);
//	myset.insert(5);
//
//	set<int>::iterator it = myset.begin();
//	while(it != myset.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	if(myset.count(5) != 0)
//		cout<<" Element found in set"<<endl;
//	else
//		cout<<" Element not found in set"<<endl;
//
//	if(myset.count(100) != 0)
//		cout<<" Element found in set"<<endl;
//	else
//		cout<<" Element not found in set"<<endl;
//
//	myset.emplace(100);
//	myset.emplace(10);
//	myset.emplace(0);
//
//
//
//	set<int>::iterator itr = myset.cbegin();
//	while(itr != myset.cend())
//	{
//		cout<<*itr<<" ";
//		itr++;
//	}
//	cout<<endl;
//
//	myset.emplace_hint(myset.begin(),4);
//	myset.emplace_hint(myset.end(),99);
//
//	for(int b: myset)
//		cout<<b<<" ";
//	cout<<endl;
//
//	 //std::set<int> myset1;
//
//	 // for (int i=1; i<=5; i++) myset1.insert(i*10);   // myset: 10 20 30 40 50
//
//	 // for(int c: myset1)
//		//  cout<<c<<" ";
//	 // cout<<endl;
//	 // std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
//	 // ret = myset1.equal_range(50);
//
//	 // std::cout << "the lower bound points to: " << *ret.first << '\n';
//	 // std::cout << "the upper bound points to: " << *ret.second << '\n';
//
//	myset.erase(4);
//	myset.erase(0);
//
//	for(int d: myset)
//		cout<<d<<" ";
//	cout<<endl;
//
//	//std::set<int> myset1;
//	//int * p;
//	//unsigned int i;
//
//	//// allocate an array of 5 elements using myset's allocator:
//	//p=myset1.get_allocator().allocate(5);
//
//	//// assign some values to array
//	//for (i=0; i<5; i++) p[i]=(i+1)*10;
//
//	//std::cout << "The allocated array contains:";
//	//for (i=0; i<5; i++) std::cout << ' ' << p[i];
//	//std::cout << '\n';
//
// // myset1.get_allocator().deallocate(p,5);
//
//	/*int highest;
//
//  std::set<int>::key_compare mycomp = myset.key_comp();
//
//  for (int i=0; i<=5; i++) myset.insert(i);
//
//  std::cout << "myset contains:";
//
//  highest=*myset.rbegin();
//  std::set<int>::iterator itc=myset.begin();
//  do {
//    std::cout << ' ' << *itc;
//  } while ( mycomp(*(++itc),highest) );
//
//  std::cout << '\n';*/
//	/*cout<<"*******************************"<<endl;
//	set<int>myset2;
//	myset2 = myset;
//
//	for(int e: myset2)
//		cout<<e<<" ";
//	cout<<endl;
//
//	myset = set<int>();
//	for(int f: myset)
//		cout<<f<<" ";
//*/
//
//  //std::set<int>::iterator itlow,itup;
//
//  //for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
//
//  //for(int g : myset)
//	 // cout<<g<<" ";
//  //cout<<endl;
//
//  //itlow=myset.lower_bound (30);                //       ^
//  //itup=myset.upper_bound (1000);                 //                   ^
//
//  //myset.erase(itlow,itup);                     // 10 20 70 80 90
//
//  //std::cout << "myset contains:";
//  //for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//  //  std::cout << ' ' << *it;
//  //std::cout << '\n';
//
//
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	map<char,int>mymap;
//	cout<<"Size of map #1 == "<<sizeof(mymap)<<endl;
//
//	cout<<"Size of map == "<<mymap.size()<<endl;
//	mymap.insert(pair<char,int>('A',1));
//	mymap.insert(pair<char,int>('B',5));
//	mymap.insert(pair<char,int>('A',1));
//	mymap.insert(pair<char,int>('G',3));
//	mymap.insert(pair<char,int>('C',3));
//	mymap.insert(pair<char,int>('H',27));
//	mymap.insert(pair<char,int>('D',9));
//
//	cout<<"Size of map == "<<mymap.size()<<endl;
//	cout<<"Max_Size of map == "<<mymap.max_size()<<endl;
//	cout<<"Size of map == "<<sizeof(mymap)<<endl;
//
//
//	map<char,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//	mymap.emplace('j',100);
//	mymap.emplace('A',233);
//	mymap.emplace('a',44);
//
//	map<char,int>::iterator ita = mymap.begin();
//
//	while(ita != mymap.end())
//	{
//		cout<<ita->first<<" "<<ita->second<<endl;
//		ita++;
//	}
//	cout<<endl;
//
//	mymap.emplace_hint(mymap.begin(),'Q',21);
//	mymap.emplace_hint(mymap.end(),'W',333);
//
//	map<char,int>::iterator itb = mymap.begin();
//
//	while(itb != mymap.end())
//	{
//		cout<<itb->first<<" "<<itb->second<<endl;
//		itb++;
//	}
//	cout<<endl;
//
//	mymap['k'];
//	mymap['l'] = 55;
//
//	map<char,int>::iterator itc = mymap.begin();
//
//	while(itc != mymap.end())
//	{
//		cout<<itc->first<<" "<<itc->second<<endl;
//		itc++;
//	}
//	cout<<endl;
//
//	/*map<char,int>::iterator itd ;
//	itd = mymap.equal_range('b');*/
//
//
//  //std::map<char,int>::iterator itd;
//
//  //itd = mymap.find('b');
//  //if (itd != mymap.end())
//  //  mymap.erase (itd);
//
//  //// print content:
//  //std::cout << "elements in mymap:" << '\n';
//  //std::cout << "a => " << mymap.find('a')->second << '\n';
//  //std::cout << "c => " << mymap.find('c')->second << '\n';
//  //std::cout << "d => " << mymap.find('d')->second << '\n';
//
//
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<unordered_map>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	unordered_map<string,int>uomap;
//	cout<<"No. of buckets == "<<uomap.bucket_count()<<endl;
//	uomap.insert(pair<string,int>("ABC",10));
//	cout<<"No. of buckets == "<<uomap.bucket_count()<<endl;
//	uomap.insert(pair<string,int>("PQR",2));
//	uomap.insert(pair<string,int>("ABC",1));
//	uomap.insert(pair<string,int>("LMN",52));
//	uomap.insert(pair<string,int>("XYZ",12));
//	uomap.insert(pair<string,int>("DLF",0));
//	uomap.insert(pair<string,int>("JKL",1));
//	uomap.insert(pair<string,int>("PQR",100));
//
//	unordered_map<string,int>::iterator it = uomap.begin();
//
//	while(it != uomap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//
//	for(auto a : uomap)
//		cout<<"Bucket Id == "<<uomap.bucket(a.first)<<endl;
//
//	cout<<"No. of buckets == "<<uomap.bucket_count()<<endl;
//	auto cnt = uomap.bucket_count();
//	for (unsigned j=0; j<cnt; ++j)
//	cout<<"Size of buckets == "<<uomap.bucket_size(j)<<endl;
//	cout<<endl;
//	uomap.emplace("RES",555);
//	uomap.emplace("RES",555);
//	uomap.emplace("STR",78);
//
//	for(auto b : uomap)
//		cout<<b.first<<" "<<b.second<<endl;
//
//	cout<<"No. of buckets == "<<uomap.bucket_count()<<endl;
//
//	cout<<endl;
//	uomap.emplace_hint(uomap.begin(),"kkk",233);
//	uomap.emplace_hint(uomap.end(),"jjj",5012);
//	for(auto c : uomap)
//	{
//		cout<<c.first<<" "<<c.second<<endl;
//		cout<<"No. of buckets == "<<uomap.bucket_count()<<endl;
//	}
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	 virtual void Show()
//	{
//		cout<<"Base Call"<<endl;
//	}
//	 virtual void Display()
//	{
//		cout<<"Base Call2"<<endl;
//	}
//
//	 friend Base Getdata(Base &b)
//	 {
//		 cout<<"friend function"<<endl;
//		 return b;
//
//	 }
//
//};
//
//class Derived : public Base
//{
//public:
//	 void Show()
//	{
//		cout<<"Derived Call"<<endl;
//	}
//	 void Display()
//	{
//		cout<<"Derived Call2"<<endl;
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	/*bptr->Display();
//	bptr-;>Show();*/
//
//	/*Derived *d = dynamic_cast<Derived *>(bptr);
//
//	d->Display();
//	d->Show();*/
//
//	bptr->Display();
//	bptr->Show();
//
//	Base b;
//	b.Display();
//	b.Show();
//
//	Base b2 = Getdata(b);
//
//	return 0;
//}

//#include<iostream>
//#include<array>
//using namespace std;
//
//int main()
//{
//	array<int,7>myarray;
//
//	myarray.fill(5);
//
//	for(int a: myarray)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	cout<<"Position 3 == "<<myarray.at(3)<<endl;
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		cout<<"Base Constructor"<<endl;
//	}
//
//	virtual ~Base()
//	{
//		cout<<"Base Destructor"<<endl;
//
//	}
//
//
//
//};
//
//class Derived : public Base
//{
//public:
//	Derived()
//	{
//		cout<<"Derived Constructor"<<endl;
//
//	}
//	~Derived()
//	{
//		cout<<"Derived Destructor"<<endl;
//
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	//bptr[10];
//	shared_ptr<int> sp ( new(int));
//	unique_ptr<int>up (new int[5]);
//	weak_ptr<int>wp1(sp);
//	weak_ptr<int>wp2=wp1;
//	shared_ptr<int>sp2 = wp1.lock();
//	int *p = new int[10];
//	shared_ptr<int>sp3(p);
//	Derived *d = dynamic_cast<Derived *>(bptr);
//
//	char*a=NULL;
//	char& q = *a;
//
//	delete bptr;
//
//return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Show()
//	{
//		cout<<"Base : Show"<<endl;
//	}
//
//	void Display()
//	{
//		cout<<"Base : Display"<<endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	void Show()
//	{
//		cout<<"Derived : Show"<<endl;
//	}
//
//	void Display()
//	{
//		cout<<"Derived : Display"<<endl;
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	Derived *dptr = dynamic_cast<Derived *> (bptr);
//	dptr->Display();
//	dptr->Show();
//
//	bptr->Show();
//	bptr->Display();
//
//
//return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int>myvect;
//
//	cout<<"Vector size == "<<myvect.size()<<endl;
//	cout<<"Vector capacity == "<<myvect.capacity()<<endl;
//	cout<<"Vector Max_size == "<<myvect.max_size()<<endl;
//
//	myvect.push_back(10);
//	myvect.push_back(20);
//	myvect.push_back(30);
//	myvect.push_back(40);
//	myvect.push_back(50);
//	myvect.push_back(60);
//	myvect.push_back(10);
//	myvect.push_back(20);
//
//	cout<<"Vector size == "<<myvect.size()<<endl;
//	cout<<"Vector capacity == "<<myvect.capacity()<<endl;
//	cout<<"Vector Max_size == "<<myvect.max_size()<<endl;
//
//	myvect.reserve(100);
//
//	cout<<"Vector (reserve)capacity == "<<myvect.capacity()<<endl;
//
//
//	vector<int>::iterator it = myvect.begin();
//
//	while( it != myvect.end())
//	{
//		cout<<*it<<" ";
//
//		it++;
//	}
//	cout<<endl;
//
//	myvect.pop_back();
//
//	for(auto itr = myvect.cbegin();itr!=myvect.cend();itr++)
//	{
//		cout<<*itr<<" ";
//	}
//	cout<<endl;
//
//	/*myvect.assign(5,100);
//
//	for(auto a: myvect)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;*/
//
//	cout<<"Vector at 3 = "<<myvect.at(3)<<endl;
//
//	/*myvect.clear();
//
//	for(int b : myvect)
//		cout<<b<<" ";
//	cout<<endl;
//*/
//	/*int* p = myvect.data();
//
//  *p = 10;
//  ++p;
//  *p = 20;
//  p[2] = 100;
//
//  std::cout << "myvector contains:";
//  for (unsigned i=0; i<myvect.size(); ++i)
//    std::cout << ' ' << myvect[i];
//  std::cout << '\n';*/
//
//	int* p = myvect.data();
//
//	p[4] = 100;
//
//	for(int c: myvect)
//		cout<<c<<" ";
//	cout<<endl;
//
//	myvect.emplace(myvect.begin(),200);
//	myvect.emplace(myvect.end(),34);
//
//	for(int d: myvect)
//		cout<<d<<" ";
//	cout<<endl;
//
//	myvect.emplace_back(22);
//	myvect.emplace_back(55);
//
//	for(int e: myvect)
//		cout<<e<<" ";
//	cout<<endl;
//
//	/*int sum (0);
//
//	while (!myvect.empty())
//	{
//		sum += myvect.back();
//	myvect.pop_back();
//	}
//
//	std::cout << "total: " << sum << '\n';*/
//
//	cout<<"Myvector front == "<<myvect.front()<<endl;
//
//
//
//	//int * q;
//	//unsigned int i;
//
// // // allocate an array with space for 5 elements using vector's allocator:
// // q = myvect.get_allocator().allocate(5);
//
// // // construct values in-place on the array:
// // for (i=0; i<5; i++) myvect.get_allocator().construct(&q[i],i);
//
// // std::cout << "The allocated array contains:";
// // for (i=0; i<5; i++) std::cout << ' ' << q[i];
// // std::cout << '\n';
//
// // // destroy and deallocate:
// // for (i=0; i<5; i++) myvect.get_allocator().destroy(&q[i]);
// // myvect.get_allocator().deallocate(q,5);
// //
//
//	myvect.insert(myvect.begin(),333);
//
//	for(int f: myvect)
//		cout<<f<<" ";
//	cout<<endl;
//
//	/*vector<int> tempvect;
//
//	tempvect = myvect;
//
//	for(int g: tempvect)
//		cout<<g<<" ";
//	cout<<endl;
//
//	for(int h: myvect)
//		cout<<h<<" ";
//	cout<<endl;*/
//
//	cout<<"vector operator[] == "<<myvect[2]<<endl;
//	cout<<"vector operator[] == "<<myvect[7]<<endl;
//
//	/*myvect.resize(5);
//
//	for(int j : myvect)
//		cout<<j<<" ";
//	cout<<endl;*/
//
//	myvect.shrink_to_fit();
//
//	cout<<"Vector shrink capacity == "<<myvect.capacity()<<endl;
//
//
//	vector<int>vect(5,100);
//
//	for(int k : vect)
//		cout<<k<<" ";
//	cout<<endl;
//	cout<<"\n **************************************** \n";
//	myvect.swap(vect);
//
//	for(int l : vect)
//		cout<<l<<" ";
//	cout<<endl;
//
//	for(int m : myvect)
//		cout<<m<<" ";
//	cout<<endl;
//
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<list>
//
//using namespace std;
//
//int main()
//{
//	list<int>mylist;
//
//	mylist.push_back(10);
//	mylist.push_back(20);
//	mylist.push_back(30);
//	mylist.push_back(40);
//	mylist.push_back(50);
//	mylist.push_front(2);
//	mylist.push_front(4);
//	mylist.push_front(6);
//
//
//	list<int>::iterator it = mylist.begin();
//
//	while(it != mylist.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	mylist.pop_front();
//	mylist.pop_back();
//
//	for(auto itr = mylist.cbegin();itr != mylist.cend(); itr++)
//		cout<<*itr<<" ";
//	cout<<endl;
//
//	for(auto ita = mylist.rbegin();ita != mylist.rend(); ita++)
//		cout<<*ita<<" ";
//	cout<<endl;
//
//	/*mylist.assign(5,100);
//
//	for(int a: mylist)
//		cout<<a<<" ";
//	cout<<endl;*/
//
//	mylist.emplace(mylist.begin(),344);
//	mylist.emplace(mylist.end(),22);
//
//	for(int b: mylist)
//		cout<<b<<" ";
//	cout<<endl;
//
//	mylist.emplace_back(55);
//	mylist.emplace_front(144);
//
//	for(int c: mylist)
//		cout<<c<<" ";
//	cout<<endl;
//
//	mylist.erase(mylist.begin());
//
//	for(int d: mylist)
//		cout<<d<<" ";
//	cout<<endl;
//
//	cout<<"List front == "<<mylist.front()<<endl;
//
//	mylist.insert(mylist.begin(),3333);
//
//	for(int e: mylist)
//		cout<<e<<" ";
//	cout<<endl;
//
//	mylist.sort();
//
//	for(int f: mylist)
//		cout<<f<<" ";
//	cout<<endl;
//
//	list<int>tmplist(4,100);
//
//	for(int g: tmplist)
//		cout<<g<<" ";
//	cout<<endl;
//
//	mylist.merge(tmplist);
//
//	for(int h: mylist)
//		cout<<h<<" ";
//	cout<<endl;
//
//	tmplist = mylist;
//
//	for(int k: tmplist)
//		cout<<k<<" ";
//	cout<<endl;
//
//	mylist.remove(100);
//
//	for(int l : mylist)
//		cout<<l<<" ";
//	cout<<endl;
//
//	mylist.remove_if([](const int &val){
//		if(val > 100)
//			return true;
//		else
//			return false;
//	});
//
//	for(int m: mylist)
//		cout<<m<<" ";
//	cout<<endl;
//
//	mylist.reverse();
//
//	for(int n: mylist)
//		cout<<n<<" ";
//	cout<<endl;
//
//	/*mylist.resize(3);
//
//	for(int o: mylist)
//		cout<<o<<" ";
//	cout<<endl;*/
//
//	list<int>templist(5,10);
//
//	for(int p: templist)
//		cout<<p<<" ";
//	cout<<endl;
//
//	mylist.swap(templist);
//
//	for(int q: mylist)
//		cout<<q<<" ";
//	cout<<endl;
//
//	mylist.unique();
//
//	for(int r: mylist)
//		cout<<r<<" ";
//	cout<<endl;
//
//
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main()
//{
//	queue<int>myque;
//
//	myque.push(10);
//	myque.push(50);
//	myque.push(40);
//	myque.push(10);
//	myque.push(20);
//
//	while(!myque.empty())
//	{
//	  cout<<myque.front()<<" ";
//	  myque.pop();
//	}
//	cout<<endl;
//
//	myque.emplace(22);
//	myque.emplace(90);
//
//	while(!myque.empty())
//	{
//	  cout<<myque.front()<<" ";
//	  myque.pop();
//	}
//
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<stack>
//
//using namespace std;
//
//int main()
//{
//	stack<int>mystack;
//
//	mystack.push(45);
//	mystack.push(1);
//	mystack.push(20);
//	mystack.push(9);
//	mystack.push(450);
//	mystack.push(66);
//
//	while(!mystack.empty())
//	{
//		cout<<mystack.top()<<" ";
//		mystack.pop();
//	}
//	cout<<endl;
//
//	mystack.emplace(11);
//	mystack.emplace(74);
//
//	while(!mystack.empty())
//	{
//		cout<<mystack.top()<<" ";
//		mystack.pop();
//	}
//	cout<<endl;
//
//	mystack.top() -=5;
//	cout<<"Stack top == "<<mystack.top()<<endl;
//
//
//	return 0;
//}


//#include<iostream>
//#include<deque>
//
//using namespace std;
//
//int main()
//{
//	deque<int>mydq;
//
//	mydq.push_back(10);
//	mydq.push_back(20);
//	mydq.push_back(10);
//	mydq.push_back(40);
//	mydq.push_back(70);
//	mydq.push_back(10);
//	mydq.push_front(1);
//	mydq.push_front(4);
//	mydq.push_front(6);
//	mydq.push_front(9);
//
//	deque<int>::iterator it = mydq.begin();
//
//	while(it != mydq.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	mydq.pop_back();
//	mydq.pop_front();
//
//	for(int a: mydq)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	mydq.emplace(mydq.begin(),45);
//	mydq.emplace(mydq.end(),2);
//
//	deque<int>::reverse_iterator itr = mydq.rbegin();
//
//	while(itr != mydq.rend())
//	{
//		cout<<*itr<<" ";
//		itr++;
//	}
//	cout<<endl;
//
//	for(int b: mydq)
//	{
//		cout<<b<<" ";
//	}
//	cout<<endl;
//
//	cout<<"Deque front == "<<mydq.front()<<endl;
//	cout<<"\n************************** \n";
//	/*while(!mydq.empty())
//	{
//		cout<<mydq.front()<<" ";
//		mydq.pop_front();
//	}
//	cout<<endl;*/
//
//	mydq.insert(mydq.begin(),222);
//	mydq.insert(mydq.end(),557);
//
//	for(int c: mydq)
//		cout<<c<<" ";
//	cout<<endl;
//
//	deque<int>tmpdq;
//
//	tmpdq = mydq;
//
//	for(int d: tmpdq)
//		cout<<d<<" ";
//	cout<<endl;
//
//	cout<<" Deque at[4] == "<<mydq.at(4)<<endl;
//
//	mydq.resize(5);
//
//	for(int e: mydq)
//		cout<<e<<" ";
//	cout<<endl;
//
//
//
//	return 0;
//}

//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main()
//{
//	priority_queue<int>pq;
//
//	pq.push(45);
//	pq.push(5);
//	pq.push(89);
//	pq.push(2);
//	pq.push(458);
//	pq.push(1);
//
//	while(!pq.empty())
//	{
//		cout<<pq.top()<<" ";
//		pq.pop();
//	}
//	cout<<endl;
//
//	pq.emplace(1);
//	pq.emplace(5566);
//	pq.emplace(4);
//
//	while(!pq.empty())
//	{
//		cout<<pq.top()<<" ";
//		pq.pop();
//	}
//	cout<<endl;
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//	set<int>myset;
//
//	myset.insert(588);
//	myset.insert(3);
//	myset.insert(450);
//	myset.insert(1);
//	myset.insert(2);
//	myset.insert(999);
//	myset.insert(8);
//	myset.insert(1);
//
//	set<int>::iterator it = myset.begin();
//
//	while(it != myset.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	if(myset.count(999)!= 0)
//		cout<<"Element found in set"<<endl;
//	else
//		cout<<"Element not found in set"<<endl;
//
//	myset.emplace_hint(myset.begin(),56);
//	myset.emplace_hint(myset.end(),22);
//
//	for(int a: myset)
//		cout<<a<<" ";
//	cout<<endl;
//
//	myset.emplace(886);
//	myset.emplace(4);
//
//	for(int b: myset)
//		cout<<b<<" ";
//	cout<<endl;
//
//	myset.erase(myset.find(22));
//
//	for(int b: myset)
//		cout<<b<<" ";
//	cout<<endl;
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//	multiset<int>mset;
//
//	mset.insert(889);
//	mset.insert(56);
//	mset.insert(1);
//	mset.insert(256);
//	mset.insert(2);
//	mset.insert(6);
//	mset.insert(57);
//	mset.insert(6);
//	mset.insert(57);
//
//	multiset<int>::iterator it = mset.begin();
//
//	while(it != mset.end())
//	{
//		cout<<*it<<" ";
//		it++;
//
//	}
//	cout<<endl;
//
//
//	return 0;
//}


//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	map<char,int>mymap;
//
//	mymap.insert(pair<char,int>('A',10));
//	mymap.insert(pair<char,int>('E',40));
//	mymap.insert(pair<char,int>('C',80));
//	mymap.insert(pair<char,int>('G',10));
//	mymap.insert(pair<char,int>('L',50));
//	mymap.insert(pair<char,int>('A',100));
//	mymap.insert(pair<char,int>('B',89));
//
//	map<char,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<"::"<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//
//	mymap.emplace('A',44);
//	mymap.emplace('F',490);
//
//	map<char,int>::iterator ita = mymap.begin();
//
//	while(ita != mymap.end())
//	{
//		cout<<ita->first<<"::"<<ita->second<<endl;
//		ita++;
//	}
//	cout<<endl;
//
//	mymap.emplace_hint(mymap.begin(),'X',200);
//	mymap.emplace_hint(mymap.end(),'R',100);
//
//	map<char,int>::iterator itb = mymap.begin();
//
//	while(itb != mymap.end())
//	{
//		cout<<itb->first<<"::"<<itb->second<<endl;
//		itb++;
//	}
//	cout<<endl;
//
//	cout<<"map == "<<mymap.count('A')<<endl<<endl;;
//
//	mymap.erase('A');
//
//	map<char,int>::iterator itc = mymap.begin();
//
//	while(itc != mymap.end())
//	{
//		cout<<itc->first<<"::"<<itc->second<<endl;
//		itc++;
//	}
//	cout<<endl;
//
//
//	//map<char,int>::iterator itd = mymap.begin();
//
//	//while(itd != mymap.end())
//	//{
//	// if(itd->second == 100)
//	//   mymap.erase(itd);
//	//
//	// //cout<<itd->first<<"::"<<itd->second<<endl;
//	// itd++;
//	//}
//	//cout<<endl;
//
//	mymap.erase(100);
//
//	map<char,int>::iterator ite = mymap.begin();
//
//	while(ite != mymap.end())
//	{
//		cout<<ite->first<<"::"<<ite->second<<endl;
//		ite++;
//	}
//	cout<<endl;
//
//
//	mymap['Q'];
//
//	map<char,int>::iterator itf = mymap.begin();
//
//	while(itf != mymap.end())
//	{
//		cout<<itf->first<<"::"<<itf->second<<endl;
//		itf++;
//	}
//	cout<<endl;
//
//	mymap['A'] = 1000;
//	mymap['J'] = 54;
//
//	map<char,int>::iterator itg = mymap.begin();
//
//	while(itg != mymap.end())
//	{
//		cout<<itg->first<<"::"<<itg->second<<endl;
//		itg++;
//	}
//	cout<<endl;
//
//
//	std::map<char,int>::iterator itlow,itup;
//
//	itlow = mymap.lower_bound('C');
//	itup = mymap.upper_bound('K');
//
//	mymap.erase(itlow,itup);
//
//	map<char,int>::iterator ith = mymap.begin();
//
//	while(ith != mymap.end())
//	{
//		cout<<ith->first<<"::"<<ith->second<<endl;
//		ith++;
//	}
//	cout<<endl;
//
//
//
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<map>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	multimap<string,int>mm;
//
//	mm.insert(pair<string,int>("ABC",11));
//	mm.insert(pair<string,int>("XYZ",53));
//	mm.insert(pair<string,int>("PQR",11));
//	mm.insert(pair<string,int>("ABC",1100));
//	mm.insert(pair<string,int>("LMN",99));
//	mm.insert(pair<string,int>("DLF",58));
//
//	multimap<string,int>::iterator it = mm.begin();
//
//	while(it != mm.end())
//	{
//		cout<<it->first<<"::"<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//
//
//	cout<<endl;
//	return 0;
//
//}

//#include <iostream>
//#include <string>
//#include <stack>
//#include <map>
//#include <iterator>
//
//using namespace std;
//
//bool isOpenBracket(char val, map<char, char> mapOfBrackets)
//{
//    map<char, char>::iterator it = mapOfBrackets.begin();
//    while(it != mapOfBrackets.end())
//    {
//         if(it->second == val)
//         {
//           return true;
//         }
//         it++;
//    }
//    return false;
//}
//bool testBracket(string s)
//{
//    stack<char> bracketStack;
//    map<char, char> bracketMap;
//
//    bracketMap['}'] = '{';
//    bracketMap[')'] = '(';
//    bracketMap[']'] = '[';
//
//    for(int i = 0; i < s.size(); i++)
//    {
//       if(isOpenBracket(s[i], bracketMap))
//       bracketStack.push(s[i]);
//
//       if(bracketMap.find(s[i]) != bracketMap.end())
//      {
//         if(bracketStack.empty())
//            return false;
//         if(bracketStack.top() != bracketMap[s[i]])
//         {
//            return false;
//         }
//         else
//            bracketStack.pop();
//
//    }
// }
// if(bracketStack.size() > 0)
//    return false;
// else
//    return true;
//}
//
//int main()
//{
//  cout<<testBracket("([(2+11)]+)")<<endl;
//  return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Sample
//{
//	// Copy Constructor should not be private if we are inserting it's
//	// objects in std::vector
//public:
//
//	Sample(const Sample & obj)
//	{
//		std::cout<<"Sample :: Copy Constructor"<<std::endl;
//	}
//public:
//	Sample()
//	{
//		std::cout<<"Sample :: Default Constructor"<<std::endl;
//	}
//
//	Sample & operator=(const Sample & obj)
//	{
//		std::cout<<"Sample :: Assignment Operator"<<std::endl;
//	}
//};
//
//int main()
//{
//	std::vector<Sample> vecOfSamples;
//	Sample obj;
//	vecOfSamples.push_back(obj);
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int>vect;
//
//	vect.push_back(10);
//	vect.push_back(11);
//	vect.push_back(12);
//	vect.push_back(13);
//	vect.push_back(14);
//	vect.push_back(10);
//	vect.push_back(15);
//	vect.push_back(13);
//	vect.push_back(12);
//	vect.push_back(11);
//
//	vector<int>::iterator it = vect.begin();
//
//	while(it != vect.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//
//
//	//vect.erase(vect.begin() + 5);
//
//	vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
//	/*vector<int>::iterator ita = vect.begin();
//
//	while(ita != vect.end())
//	{
//		if(*ita == 10)
//			ita == vect.erase(ita);
//		else
//		ita++;
//	}
//	cout<<endl;*/
//
//	for(int a: vect)
//	{
//		cout<<a<<" ";
//
//	}
//
//	cout<<endl;
//
//	 //for(; it != vect.end(); it++)   // Undefined Behavior
//  //      std::cout<<(*it)<<"  ";
//
//	return 0;
//}


//#include <iostream>
//#include <map>
//#include <string>
//#include <iterator>
//
//struct WordGreaterComparator
//{
//    bool operator()(const std::string & left, const std::string & right) const
//    {
//        return (left > right);
//    }
//};
//
//int main()
//{
//
//    std::cout<<"Default sorting criteria for keys i.e. operator < for std::string"<<std::endl;
//    // Default sorting criteria for keys i.e. operator < for std::string
//    std::map<std::string, int > mapOfWords;
//
//    mapOfWords.insert(std::make_pair("earth", 1));
//    mapOfWords.insert(std::make_pair("moon", 2));
//    mapOfWords.insert(std::make_pair("sun", 3));
//	mapOfWords.insert(std::pair<std::string,int>("rohit",4));
//
//    std::map<std::string, int>::iterator it = mapOfWords.begin();
//    for( ; it != mapOfWords.end(); it++)
//        std::cout<<it->first<<" :: "<<it->second<<std::endl;
//
//    std::cout<<"External sorting criteria for keys "<<std::endl;
//    std::map<std::string, int, WordGreaterComparator > mapOfWords_2;
//
//    mapOfWords_2.insert(std::make_pair("earth", 1));
//    mapOfWords_2.insert(std::make_pair("moon", 2));
//    mapOfWords_2.insert(std::make_pair("sun", 3));
//	mapOfWords_2.insert(std::pair<std::string,int>("rohit",4));
//    for(std::map<std::string, int>::iterator it = mapOfWords_2.begin(); it != mapOfWords_2.end(); it++)
//        std::cout<<it->first<<" :: "<<it->second<<std::endl;
//
//    // Compile Error as 2 std::map objects have different sorting criteria0
//    //if(mapOfWords == mapOfWords_2)
//    //    std::cout<<"Maps are same"<<std::endl;
//
//    return 0;
//}

//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//
//int main()
//{
//std::shared_ptr p1(new int());
//*p1 = 78;
//std::cout<<"p1 = "<<*p1<<std::endl;
//
//// Shows the reference count
//std::cout<<"Reference count = "<<p1.use_count()<<std::endl;
//
//// Second shared_ptr object will also point to same pointer internally
//// It will make the reference count to 2.
//std::shared_ptr p2(p1);
//
//// Shows the reference count
//std::cout<<"Reference count = "<<p1.use_count()<<std::endl;
//
//if(p1 == p2)
//{
//std::cout<<"p1 and p2 are pointing to same pointer\n";
//}
//
//// Reset the shared_ptr, in this case it will not point to any Pointer internally
//// hence its reference count will become 0.
//p1.reset();
//std::cout<<"p1 = "<<p1.use_count()<<std::endl;
//
//// Reset the shared_ptr, in this case it will point to a new Pointer internally
//// hence its reference count will become 1.
//p1.reset(new int(11));
//std::cout<<"p1 = "<<p1.use_count()<<std::endl;
//
//// Assigning nullptr will de-attach the associated pointer and make it to point null
//p1 = nullptr;
//std::cout<<"p1 = "<<p1.use_count()<<std::endl;
//
//if(!p1)
//{
//std::cout<<"p1 is NULL"<<std::endl;
//}
//return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Display(int a = 10)
//	{
//		cout<<a<<endl;
//	}
//};
//
//class Derived: public Base
//{
//public:
//	 void Display(int a = 20)
//	{
//		cout<<a<<endl;
//	}
//};
//
//int main()
//{
//	int c;
//	Base *bptr = new Derived();
//	bptr->Display();
//	return 0;
//}
//


//#include <stdio.h>
//#include <limits.h> //For INT_MIN
//
//#define MAX_SIZE 1000
//
//int main()
//{
//    int arr[MAX_SIZE], N, i;
//    int max1, max2;
//
//    /*
//     * Reads size and elements in the array
//     */
//    printf("Enter size of the array (1-1000): ");
//    scanf("%d", &N);
//    printf("Enter elements in the array: ");
//    for(i=0; i<N; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    max1 = max2 = 0;
//
//    /*
//     * Checks for first largest and second largest till N
//     */
//    for(i=0; i<N; i++)
//    {
//        if(arr[i] > max1)
//        {
//            /*
//             * If current element of the array is first largest
//             * then make current max as second max
//             * and then max as current array element
//             */
//            max2 = max1;
//            max1 = arr[i];
//        }
//        else if(arr[i] > max2)
//        {
//            /*
//             * If current array element is less than first largest
//             * but is greater than second largest then make it
//             * second largest
//             */
//            max2 = arr[i];
//        }
//    }
//
//    printf("First largest = %d\n", max1);
//    printf("Second largest = %d", max2);
//	printf("\n ");
//
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//   int i = 8;
//   int p = i++*i++;
//   printf("%d\n", p);
//}

//#include <stdio.h>
//int x = 20;
//int f1() { x = x+10; return x;}
//int f2() { x = x-5;  return x;}
//int main()
//{
//  int p = f1() + f2();
//  printf ("p = %d", p);
//  return 0;
//}


//// PROGRAM 1
//#include <stdio.h>
//int f1() { printf ("Geeks"); return 1;}
//int f2() { printf ("forGeeks"); return 1;}`
//int main()
//{
//  int p = f1() + f2();
//  return 0;
//}


//#include<iostream>
//#include<set>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	set<int>myset;
//	//vector<vector<int>>myvect(5, vector<int>(4, 1));
//
//	myset.insert(20);
//	myset.insert(11);
//	myset.insert(5);
//	myset.insert(20);
//	myset.insert(10);
//	myset.insert(1);
//	myset.insert(5);
//	myset.insert(2);
//
//	//for(int v : myvect)
//
//	vector <std::vector<int> > vec2D(6, std::vector<int>(5, 1));
//
//	for(auto vec : vec2D)
//	{
//		for(auto x : vec)
//			std::cout<<x<<" , ";
//		std::cout << std::endl;
//	}
//
//
//	set<int>:: iterator it = myset.begin();
//
//	while(it != myset.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	set<int>:: iterator ita = myset.find(100);
//
//	if(ita != myset.end())
//		cout<<"Element found"<<endl;
//	else
//		cout<<"Element not found"<<endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
// void displayVector(std::vector<int> & vec);
// void removeAllMatchingElements_nonEfficient(std::vector<int> & vec, int elem);
// void removeAllMatchingElements_Efficient(std::vector<int> & vec, int elem);
//
//
//void removeAllMatchingElements_nonEfficient(std::vector<int> & vec, int elem)
//{
//   std::vector<int>::iterator it = vec.begin();
//   while(it != vec.end())
//   {
//     if(*it == elem)
//     {
//        it = vec.erase(it);
//     }
//     else
//        it++;
//  }
//}
//
//void removeAllMatchingElements_Efficient(std::vector<int> & vec, int elem)
//{
//    vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
//}
//
//void displayVector(std::vector<int> & vec)
//{
//   std::vector<int>::iterator it = vec.begin();
//   while(it != vec.end())
//       std::cout<<(*it++)<<" ";
//   std::cout<<std::endl;
//}
//int main()
//{
//   int arr[10] = {1,2,5,4,5,1,5,7,8,9};
//
//  /* std::vector<int> vec(arr , arr + 10);
//   removeAllMatchingElements_nonEfficient(vec, 5);
//   displayVector(vec);*/
//
//   std::vector<int> vec2(arr , arr + 10);
//   removeAllMatchingElements_Efficient(vec2, 5);
//   displayVector(vec2);
//
//   return 0;
//}


//#include<iostream>
//#include<vector>
//#include <algorithm>
////#include <iterator>
//
//using namespace std;
//
//int main()
//{
//	vector<int>myvect;
//
//	myvect.push_back(10);
//	myvect.push_back(3);
//	myvect.push_back(1);
//	myvect.push_back(80);
//	myvect.push_back(3);
//	myvect.push_back(5);
//	myvect.push_back(3);
//	myvect.push_back(5);
//	myvect.push_back(8);
//	myvect.push_back(3);
//	myvect.push_back(6);
//
//	vector<int>::iterator it = myvect.begin();
//
//	while(it != myvect.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	myvect.erase(std::remove(myvect.begin(),myvect.end(),3),myvect.end());
//
//	for(auto a: myvect)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//int main() {
//    try {
//        std::vector<int> vec;
//
//		vec.push_back(4);
//		vec.push_back(3);
//		vec.push_back(1);
//		vec.push_back(3);
//		vec.at(5); // Throws an exception, std::out_of_range (indexing for vec is from 0-3 not 1-4)
//    }
//
//    // An exception handler, catches std::out_of_range, which is thrown by vec.at(4)
//    catch (std::out_of_range& e) {
//        std::cerr << "Accessing a non-existent element: " << e.what() << '\n';
//    }
//
//    // To catch any other standard library exceptions (they derive from std::exception)
//    catch (std::exception& e) {
//        std::cerr << "Exception thrown: " << e.what() << '\n';
//    }
//
//    // Catch any unrecognised exceptions (i.e. those which don't derive from std::exception)
//    catch (...) {
//        std::cerr << "Some fatal error\n";
//    }
//}

//#include<iostream>
//#include<vector>
//#include<numeric> // for iota()
//using namespace std;
//int main()
//{
//    // Initializing array with 0 values
//    int ar[6] =  {0};
//
//    // Using iota() to assign values
//    iota(ar, ar+6, 20);
//
//    // Displaying the new array
//    cout << "The new array after assigning values is : ";
//    for (int i=0; i<6 ; i++)
//       cout << ar[i] << " ";
//
//    cout<<endl;
//	vector< vector<int>>myvect(5,vector<int>(4,1));\
//
//		for(auto v : myvect)
//		{
//			for(auto a: v)
//				cout<<a<<",";
//			cout<<endl;
//		}
//
//		cout<<endl;
//	return 0;
//
//}

//#include<iostream>
//#include<map>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	map<string,int>mymap;
//
//	mymap.insert(pair<string,int>("ABC",1));
//	mymap.insert(pair<string,int>("PQR",56));
//	mymap.insert(pair<string,int>("XYZ",1));
//	mymap.insert(pair<string,int>("ABC",1));
//	mymap.insert(pair<string,int>("LMN",199));
//	mymap.insert(pair<string,int>("DLF",23));
//	mymap.insert(pair<string,int>("LOM",899));
//
//	map<string , int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//
//
//
//
//
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<vector<int>>myvetor(5,vector<int>(4,1));
//
//	for(auto a: myvetor)
//	{
//		for(auto b : a)
//		{
//			cout<<b<<",";
//
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//
//	return 0;
//}
//

//#include<iostream>
//
//using namespace std;
//
//int secondlargest(int arr[],int n)
//{
//	int max1 = 0;
//	int max2 = 0;
//	int max3 = 0;
//
//	if(n < 3)
//	{
//		cout<<"arr size less than 3"<<endl;
//	}
//
//	for(int i =0; i<n; i++)
//	{
//		if(arr[i] > max1)
//		{
//			max3 = max2;
//			max2 = max1;
//			max1 = arr[i];
//		}
//		else if(arr[i] >  max2)
//		{
//			max3 = max2;
//			max2 = arr[i];
//		}
//		else if(arr[i] > max3)
//		{
//			max3 = arr[i];
//		}
//	}
//	cout<<"First largest == "<<max1<<endl;
//	cout<<"Second largest == "<<max2<<endl;
//	cout<<"Third largest == "<<max3<<endl;
//
//	return 0;
//}
//
//int main()
//{
//	int arr[] = {56,89,1,2,4,5,7,9,98};
//
//	int n = sizeof(arr)/sizeof(arr[0]);
//
//	cout<<"Array is : ";
//	for(int i =0; i<n; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	secondlargest(arr,n);
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num;
//	int fact = 1;
//	cout<<"Enter the num for factorial == ";
//	cin>>num;
//	cout<<endl;
//	for(int i =1;i<=num; i++)
//	{
//		fact = fact * i;
//	}
//
//	cout<<"Factorial of num  == "<<fact<<endl;
//
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//
//using namespace std;
//
//int main()
//{
//	char str[100];
//	int len;
//	bool bFlag = false;
//
//	cout<<"Enter string == ";
//	cin>>str;
//	cout<<endl;
//
//	len = strlen(str);
//
//	for(int i =0; i<(len/2); i++)
//	{
//		if(str[i] == str[len -1-i])
//			bFlag = true;
//	}
//
//	if(bFlag)
//		cout<<"String is Palindrome"<<endl;
//	else
//		cout<<"String is not Palindrome"<<endl;
//
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<memory>
//
//using namespace std;
//
//int main()
//{
//	char str[100];
//	//shared_ptr sp1 = make_shared(12);
//	shared_ptr<int>sp(new int[5]);
//	weak_ptr<int>wp = sp;
//	weak_ptr<int>wp1 = wp;
//	unique_ptr<int>up(new int [12]);
//	int len;
//	bool bFlag = false;
//
//	cout<<"Enter string == ";
//	cin>>str;
//	cout<<endl;
//
//	len = strlen(str);
//
//	for(int i =0; i<(len/2); i++)
//	{
//		if(str[i] == str[len -1-i])
//			bFlag = true;
//	}
//
//	if(bFlag)
//		cout<<"String is Palindrome"<<endl;
//	else
//		cout<<"String is not Palindrome"<<endl;
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int main = 56;
//    printf("%d", main);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//   float a = 3.14, *fptr;
//   fptr = &a;
//
//   printf("Size of Float Pointer : %d", sizeof(fptr));
//   return (0);
//}

//#include<stdio.h>
//int main()
//{
//    fork();
//    fork();
//    printf("Hello world\n");
//}

//#include<stdio.h>
//int main()
//{
//        int x=35;
//        printf("%d %d %d",x==35,x=50,x>40);
//        return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	char *str = "String";
//	char *str1 = "Strong";
//
//	for(int i =0;i<strlen(str);i++)
//	{
//		for(int j =0;j<strlen(str1);j++)
//		{
//			if(str[i] == str1[j])
//				cout<<str[i];
//		}
//	}
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	void Display()
//	{
//		cout<<" Base : Dipslay "<<endl;
//	}
//
//	void Show()
//	{
//		cout<<" Base : Show "<<endl;
//	}
//
//};
//
//class Derived : public Base
//{
//public:
//	void Print()
//	{
//		cout<<"Derived : Print"<<endl;
//	}
//
//};
//int main()
//{
//	Derived d;
//
//	d.Display();
//	d.Print();
//	d.Show();
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class A {
//  public:
//    virtual void fun()
//    { cout<<"\n A::fun() called ";}
//};
//
//class B: public A {
//  public:
//    void fun()
//    { cout<<"\n B::fun() called "; }
//};
//
//class C: public B {
//  public:
//    void fun()
//    { cout<<"\n C::fun() called "; }
//};
//
//int main()
//{
//   C c; // An object of class C
//   B *b = &c; // A pointer of type B* pointing to c
//   b->fun();  // this line prints "C::fun() called"
//   getchar();
//   return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//
//public:
//	virtual void Display(int x = 10)
//	{
//		cout<<"Base : x == "<<x<<endl;
//	}
//};
//
//class Derived :  public Base
//{
//public:
//	void Display(int x = 20)
//	{
//		cout<<"Derived : x == "<<x<<endl;
//	}
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	bptr->Display();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Box {
//	private:
//		double length;
//		double width;
//		double height;
//	public:
//		Box(double boxLength, double boxWidth, double boxHeight)
//			:length(boxLength), width(boxWidth), height(boxHeight) {}
//
//		// Compute the volume of a box.
//		double volume() const {
//			return length*width*height;
//		}
//
//		// First inline function
//		inline bool operator<(const Box& someBox) const {
//			return volume() < someBox.volume();
//		}
//
//		// Second inline function
//		inline bool operator<(const double someValue) const {
//			return volume() < someValue;
//		}
//
//		// Third inline function
//		inline bool operator>(const Box& someBox) const {
//			return volume() > someBox.volume();
//		}
//
//		// Fourth inline function
//		inline bool operator>(const double someValue) const {
//			return volume() > someValue;
//		}
//
//
//};
//
//
//int main() {
//	Box myBox(15.0, 10.0, 5.0);
//	Box myBox2(15.0, 5.0, 5.0);
//
//	cout << "The myBox volume is: " << myBox.volume() << "\n";
//	cout << "The myBox2 volume is: " << myBox2.volume() << "\n";
//
//	// Trying the less than binary operator
//	if(myBox < myBox2) {
//		cout << "The myBox volume is less than myBox2 volume!\n";
//	}else{
//		cout << "The myBox volume is not less than myBox2 volume!\n";
//	}
//
//	// Trying the less than binary operator
//	if(myBox < 1000) {
//		cout << "The myBox volume is less than 1000!\n";
//	}else{
//		cout << "The myBox volume is not less than 1000!\n";
//	}
//
//	// Trying the greater than binary operator
//	if(myBox > myBox2) {
//		cout << "The myBox volume is greater than myBox2 volume!\n";
//	}else{
//		cout << "The myBox volume is not greater than myBox2 volume!\n";
//	}
//
//	// Trying the greater than binary operator
//	if(myBox > 500) {
//		cout << "The myBox volume is greater than 500!\n";
//	}else{
//		cout << "The myBox volume is not greater than 500!\n";
//	}
//
//	return 0;
//}
//


//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	map<char,int>mymap;
//
//	mymap.insert(pair<char,int>('A',23));
//	mymap.insert(pair<char,int>('B',2));
//	mymap.insert(pair<char,int>('E',23));
//	mymap.insert(pair<char,int>('C',89));
//	mymap.insert(pair<char,int>('A',56));
//	mymap.insert(pair<char,int>('M',74));
//	mymap.insert(pair<char,int>('D',23));
//
//	map<char,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//#include<list>
//#include<memory>
//
//
//using namespace std;
//
//int main()
//{
//	list<int>mylist;
//	shared_ptr<int>sp (new(int[12]));
//	weak_ptr<int>wp =sp;
//	unique_ptr<int>up(new int[12]);
//	//shared_ptr sp = make_shared(12);
//
//
//	mylist.push_back(45);
//	mylist.push_back(5);
//	mylist.push_back(9);
//	mylist.push_back(10);
//	mylist.push_back(45);
//	mylist.push_back(9);
//
//	list<int>::iterator it = mylist.begin();
//	while(it != mylist.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	/*list<int>::iterator ita = mylist.begin();
//
//	while(ita != mylist.end())
//	{
//		if(*it > 9)
//			mylist.erase(it);
//		cout<<*it<<" ";
//		it++;
//	}*/
//
//	mylist.erase(mylist.begin());
//
//	for(int a:mylist)
//		cout<<a<<" ";
//	cout<<endl;
//
//
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//
//class Base
//{
//public:
//	virtual void Display(int x = 10)
//	{
//		cout<<"Base : Display x == "<<x<<endl;
//	}
//};
//class Derived:public Base
//{
//public:
//	void Display(int x = 20)
//	{
//		cout<<"Derived : Display x ==  "<<x<<endl;
//	}
//	void Show()
//	{
//		cout<<"Derived : Show "<<endl;
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//
//	//bptr->Display();
//	Derived *d = dynamic_cast<Derived *>(bptr);
//	d->Display();
//	d->Show();
//
//
//	return 0;
//}

//#include<stdlib.h>
//#include<stdio.h>
//
///* A linked list node */
//struct node
//{
//  int data;
//  struct node *next;
//};
//
//
///* Prints a linked list in reverse manner */
//void fun1(struct node* head)
//{
//  if(head == NULL)
//    return;
//
//  fun1(head->next);
//  printf("%d  ", head->data);
//}
//
///* prints alternate nodes of a Linked List, first
//  from head to end, and then from end to head. */
//void fun2(struct node* start)
//{
//  if(start == NULL)
//    return;
//  printf("%d  ", start->data);
//
//  if(start->next != NULL )
//    fun2(start->next->next);
//  printf("%d  ", start->data);
//}
//
///* UTILITY FUNCTIONS TO TEST fun1() and fun2() */
///* Given a reference (pointer to pointer) to the head
//  of a list and an int, push a new node on the front
//  of the list. */
//void push(struct node** head_ref, int new_data)
//{
//  /* allocate node */
//  struct node* new_node =
//          (struct node*) malloc(sizeof(struct node));
//
//  /* put in the data  */
//  new_node->data  = new_data;
//
//  /* link the old list off the new node */
//  new_node->next = (*head_ref);
//
//  /* move the head to point to the new node */
//  (*head_ref)    = new_node;
//}
//
///* Drier program to test above functions */
//int main()
//{
//  /* Start with the empty list */
//  struct node* head = NULL;
//
//  /* Using push() to construct below list
//    1->2->3->4->5  */
//  push(&head, 5);
//  push(&head, 4);
//  push(&head, 3);
//  push(&head, 2);
//  push(&head, 1);
//
//  printf("\n Output of fun1() for list 1->2->3->4->5 \n");
//  fun1(head);
//
//  printf("\n Output of fun2() for list 1->2->3->4->5 \n");
//  fun2(head);
//
//  getchar();
//  return 0;
//}


//// C++ code to demonstrate copy of vector
//// by assign() and copy().
//#include<iostream>
//#include<vector> // for vector
//#include<algorithm> // for copy() and assign()
//#include<iterator> // for back_inserter
//using namespace std;
//int main()
//{
//    // Initializing vector with values
//    vector<int> vect1;
//	vect1.push_back(1);
//	vect1.push_back(2);
//	vect1.push_back(3);
//	vect1.push_back(4);
//
//
//    // Declaring new vector
//    vector<int> vect2;
//
//    // Copying vector by copy function
//    //copy(vect1.begin(), vect1.end(), back_inserter(vect2));
//	//vect2.assign(vect1.begin(),vect1.end());
//	copy(vect1.begin(), vect1.end(), back_inserter(vect2));
//
//    cout << "Old vector elements are : ";
//    for (int i=0; i<vect1.size(); i++)
//        cout << vect1[i] << " ";
//    cout << endl;
//
//    cout << "New vector elements are : ";
//    for (int i=0; i<vect2.size(); i++)
//        cout << vect2[i] << " ";
//    cout<< endl;
//
//    // Changing value of vector to show that a new
//    // copy is created.
//    vect1[0] = 2;
//
//    cout << "The first element of old vector is :";
//    cout << vect1[0] << endl;
//    cout << "The first element of new vector is :";
//    cout << vect2[0] <<endl;
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int arr[]={4,1,2,9,5,7,6,8,0};
//	int n = sizeof(arr)/sizeof(arr[0]);
//
//	for(int i = 0;i<n; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//
//	sort(arr,arr+n);
//	cout<<"Sorted array:";
//	for(int i = 0;i<n; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//
//	sort(arr,arr+n,greater<int>());
//	cout<<"Sorted array:";
//	for(int i = 0;i<n; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//}

//#include<iostream>
//#include<map>
//using namespace std;
//
//int main()
//{
//	map<char,int>mymap;
//
//	mymap.insert(pair<char,int>('A',2));
//	mymap.insert(pair<char,int>('Z',4));
//	mymap.insert(pair<char,int>('G',45));
//	mymap.insert(pair<char,int>('B',2));
//	mymap.insert(pair<char,int>('A',89));
//	mymap.insert(pair<char,int>('E',11));
//
//	map<char,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//	mymap['T'];
//	mymap['P']= 100;
//
//	map<char,int>::iterator ita = mymap.begin();
//
//	while(ita != mymap.end())
//	{
//		cout<<ita->first<<" "<<ita->second<<endl;
//		ita++;
//	}
//
//	cout<<mymap.at('P')<<endl;
//
//	map<char,int>::iterator itb = mymap.find('Q');
//
//	if(itb != mymap.end())
//		cout<<"Element found"<<endl;
//	else
//		cout<<"Element not found"<<endl;
//
//	map<char,int>::iterator itc = mymap.begin();
//
//	while(itc != mymap.end())
//	{
//		if(itc->second > 50)
//			mymap.erase(itc->first);
//		cout<<itc->first<<" "<<itc->second<<endl;
//		itc++;
//	}
//	return 0;
//}
//

//// Simple C++ program to demonstrate use of copy-and-swap
//// idiom by improving above code.
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class anyArrayClass
//{
//    int size;
//    char *ptr;
//public:
//    anyArrayClass(int s=0):size(s),
//     ptr(size? new int[size]:nullptr) {}
//
//    // Copy constructor
//    anyArrayClass(const anyArrayClass& obj):size(obj.size),
//                           ptr(size? new int[size]:nullptr)
//    {
//        memmove(ptr, obj.ptr, size*sizeof(int));
//
//		cout<<"Copy Constructor == "<<ptr<<endl;
//    }
//
//    friend void swap(anyArrayClass& obj1, anyArrayClass& obj2)
//    {
//        std::swap(obj1.size, obj2.size);
//        std::swap(obj1.ptr, obj2.ptr);
//    }
//
//    // overloaded assignment operator
//    // argument passed by value. calls copy ctor
//    anyArrayClass& operator=(anyArrayClass obj)
//    {
//        // calling friend function
//        swap(*this, obj);
//		cout<<"Copy Constructor == "<<obj.ptr<<endl;
//
//        return *this;
//    }
//
//    ~anyArrayClass()
//    {
//        delete[] ptr;
//    }
//};
//int main()
//{
//	int* name = "Rohit";
//
//	anyArrayClass a(name);
//	anyArrayClass a1 = a;
//	anyArrayClass a2;
//	a2 = a1;
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class base {
//    int arr[10];
//};
//
//class b1: virtual public base { };
//
//class b2: virtual public base { };
//
//class derived: public b1, public b2 {};
//
//int main(void)
//{
//  cout<<sizeof(derived);
//  getchar();
//  return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//  int x;
//public:
//  Test(int x = 0) { this->x = x; }
//  void change(Test *t) { this = t; }
//  void print() { cout << "x = " << x << endl; }
//};
//
//int main()
//{
//  Test obj(5);
//  Test *ptr = new Test (10);
//  obj.change(ptr);
//  obj.print();
//  return 0;
//}


//#include <iostream>
//using namespace std;
//class Point
//{
//    int x, y;
//public:
// Point(int i = 0, int j =0)
//   { x = i; y = j;  }
//   int getX() const { return x; }
//   int getY() {return y;}
//};
//
//int main()
//{
//    const Point t;
//    cout << t.getX() << " ";
//    cout << t.gety();
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int arr[] = {1,2,3,4,5};
//	int sum = 0;
//	int n = sizeof(arr)/sizeof(arr[0]);
//	for(int i = 0; i<n;i++)
//	{
//		sum = sum + arr[i];
//	}
//
//	cout<<"Sum == "<<sum<<endl;
//	return 0;
//}

//#include <stdio.h>
//#define N 4
//
//// This function multiplies A[][] and B[][], and stores
//// the result in C[][]
//void multiply(int A[][N], int B[][N], int C[][N])
//{
//    int i, j, k;
//    for (i = 0; i < N; i++)
//    {
//        for (j = 0; j < N; j++)
//        {
//            C[i][j] = 0;
//            for (k = 0; k < N; k++)
//                C[i][j] += A[i][k]*B[k][j];
//        }
//    }
//}
//
//int main()
//{
//    int A[N][N] = { {1, 1, 1, 1},
//                    {2, 2, 2, 2},
//                    {3, 3, 3, 3},
//                    {4, 4, 4, 4}};
//
//    int B[N][N] = { {1, 1, 1, 1},
//                    {2, 2, 2, 2},
//                    {3, 3, 3, 3}};
//
//    int C[N][N]; // To store result
//    int i, j;
//    multiply(A, B, C);
//
//    printf("Result matrix is \n");
//    for (i = 0; i < N; i++)
//    {
//        for (j = 0; j < N; j++)
//           printf("%d ", C[i][j]);
//        printf("\n");
//    }
//
//    return 0;
//}


///* getMissingNo takes array and size of array as arguments*/
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//int getMissingNo(int a[], int n)
//{
//    int i;
//    int x1 = a[0]; /* For xor of all the elements in array */
//    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
//
//    for (i = 1; i< n; i++)
//        x1 = x1^a[i];
//    cout<<"x1 == "<<x1<<endl;
//    for ( i = 2; i <= n+1; i++)
//        x2 = x2^i;
//    cout<<"x2 == "<<x2<<endl;
//
//    return (x1^x2);
//}
//
///*program to test above function */
//int main()
//{
//    int a[] = {1, 2, 4, 5, 6};
//    int miss = getMissingNo(a, 5);
//    printf("%d", miss);
//    getchar();
//}

//#include<stdio.h>
//
//int main()
//{
//	int num;
//
//	printf("\n Enter no.");
//	scanf("%d",&num);
//
//	if((num&1)? printf("\n Odd no."): printf("Even no."));
//
//	return 0;
//}

//#include<windows.h>
//
//int main()
//{
//	WCHAR wszPath[MAX_PATH] = L"C:\\test";
//	WCHAR *wszptr = NULL;
//	wszptr = ::wcschr(wszPath,L':');
//    if(wszptr != NULL)
//	{
//		wszptr++;
//	}
//
//	MessageBox(NULL,wszptr,L"TRUE",MB_OK | MB_TOPMOST);
//	return 0;
//}

//
//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//
////This design is not thread safe
//class Singleton{
//public:
//	//this function creates Singleton object and return it to users.
//
//	//This design is not thread safe
//    static Singleton* GetInstance(){
//
//			if(NULL == s_instance)//Inside this condition multiple threads can enter and create objects
//			{
//				 s_instance=new Singleton();
//			}
//		return s_instance;
//	}
//   ~Singleton(){}
//private:
//	Singleton(){cout<<"constructor...\n";}
//	static Singleton* s_instance;
//
//};
////initiaize static variables here
//Singleton *Singleton::s_instance = 0;
//
//DWORD WINAPI threadFunction(LPVOID lpParam)
//{
//	//Get object of singleton class into a thread
//	Singleton *ob2=Singleton::GetInstance();
//	cout<<"Address of object in thread:"<<ob2<<endl;
//
//	return 0;
//}
//
//
//int main(){
//
//	HANDLE hThread;
//	DWORD ThreadId;
//
//	hThread = CreateThread(
//			NULL,        // default security attributes
//			0,         // use default stack size
//			threadFunction,    // thread function
//			NULL,        // argument to thread function
//			0,         // use default creation flags
//			&ThreadId
//			);     // returns the thread identifier
//
//	if (hThread == NULL){
//		printf("CreateThread() failed, error: %d.\n", GetLastError());
//		return 1;
//	}
//
//	//Get object of singleton class into main thread
//	Singleton *ob1 = Singleton::GetInstance();
//	cout<<"Address of object in main thread:"<<ob1<<endl;
//
//	WaitForSingleObject(hThread,INFINITE);//wait for thread to finish.
//
//
//	if (CloseHandle(hThread) != 0){
//		 printf("Thread handle closed.\n");
//	}
//
//	return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//
////Car class for which we have to implement
//// a Smart pointer.
//class Car{
//
//public:
//	void Run(){
//		cout<<"Car Running..."<<"\n";
//	}
//};
//
////Smart pointer for class Car
//class CarSP{
//
//	Car * sp;
//
//public:
//	//Initialize Car pointer when Car
//	//object is createdy dynamically
//	CarSP(Car * cptr):sp(cptr)
//	{
//	}
//
//	// Smart pointer destructor that will de-allocate
//	//The memory allocated by Car class.
//	~CarSP(){
//		printf("Deleting dynamically allocated car object\n");
//		delete sp;
//	}
//
//	//Overload -> operator that will be used to
//	//call functions of class car
//	Car* operator-> ()
//	{
//		return sp;
//	}
//};
//
//
////Test
//int main(){
//
//	//Create car object and initialize to smart pointer
//	CarSP ptr(new Car());
//	ptr->Run();
//
//	//Memory allocated for car will be deleted
//	//Once it goes out of scope.
//	return 0;
//}


//#include<iostream>

//using namespace std;
//
//class Base
//{
//public:
//	virtual void Display()
//	{
//		cout<<"Base: Display"<<endl;
//
//	}
//	void Show()
//	{
//		cout<<"Base: Show"<<endl;
//	}
//};
//class Derived: public Base
//{
//public:
//	 void Display()
//	{
//		cout<<"Derived: Display"<<endl;
//
//	}
//	void Show()
//	{
//		cout<<"Derived: Show"<<endl;
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	//bptr->Display();
//	//bptr->Show();
//	Derived *d = dynamic_cast<Derived *>(bptr);
//	d->Display();
//	d->Show();
//
//	return 0;
//}

//using namespace std;
//
//
//class A {
//public:
//	virtual void func() { printf("Class A :func()\n"); }
//	        void func2(){ printf("Class A :func2()\n"); }//Not virtual
//};
//
//
//class B : public A {
//public:
//	void func() { printf("Class B :func()\n"); }
//
//	void func2(){ printf("Class B :func2()\n"); }
//};
//
//class C : public A {
//public:
//	void func() { printf("Class C :func()\n"); }
//};
//
//
////-----Client code------
//void f(A* arg) {
//
//	//call
//  B* bp = dynamic_cast<B*>(arg);
//
//  //Call Specific class B function.
//  if (bp)
//  {
//		bp->func();
//		bp->func2();
//  }
//  else{
//	  //Call respective class function
//    arg->func();
//  }
//};
//
//int main()
//{
//	A* ap1 = new B();
//	f(ap1);
//
//
//	//operate C object
//	A* ap2 = new C();
//	f(ap2);
//
//return 0;
//}


//#include<windows.h>
//
//#define ZONE_IDENTIFIER     L":Zone.Identifier"
//
//int main()
//{
//	HANDLE hHandle = NULL;
//	WCHAR wszPath[MAX_PATH] = L"C:\\Users\\Rohit.Khajindar\\Downloads\\REVE_TotalSecurity_x86.exe";//L"C:\\Users\\Rohit.Khajindar\\Downloads\\VirtualBox-5.1.14-112924-Win.exe";
//
//	wcscat(wszPath,ZONE_IDENTIFIER);
//	::MessageBox(NULL,wszPath,L"wszPath",MB_OK | MB_TOPMOST);
//	hHandle =  CreateFile(
//					wszPath,
//					GENERIC_READ,
//					FILE_SHARE_READ | FILE_SHARE_WRITE,
//					NULL,
//					OPEN_EXISTING,
//					FILE_ATTRIBUTE_NORMAL,
//					NULL
//					);
//
//	if(hHandle == INVALID_HANDLE_VALUE)
//	{
//		::MessageBox(NULL,L"File Create Fail.",L"TRUE",MB_OK | MB_TOPMOST);
//	}
//	else
//	{
//		::MessageBox(NULL,L"File Create Success.",L"TRUE",MB_OK | MB_TOPMOST);
//	}
//
//
//	return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//	set<int>myset;
//
//	cout<<"Set size == "<<myset.size()<<endl;
//	//cout<<"set max_size == "<<myset.max_size<<endl;
//
//	myset.insert(10);
//	myset.insert(7);
//	myset.insert(1);
//	myset.insert(30);
//	myset.insert(10);
//	myset.insert(5);
//
//	set<int>::iterator it = myset.begin();
//
//	while(it != myset.end())
//	{
//		cout<<*it<<" ";
//		it++;
//
//	}
//	cout<<endl;
//
//	myset.emplace(50);
//	myset.emplace(2);
//
//	for(int a: myset)
//		cout<<a<<" ";
//	cout<<endl;
//
//	myset.emplace_hint(myset.begin(),70);
//	myset.emplace_hint(myset.end(),5);
//
//	for(int b : myset)
//		cout<<b<<" ";
//	cout<<endl;
//
//	set<int>::iterator ita = myset.find(50);
//
//	while(ita != myset.end())
//	{
//		cout<<"Element found"<<endl;
//		ita++;
//	}
//
//	set<int>test;
//
//	cout<<"Allocator : "<<endl;
//	test.get_allocator().allocate(5);
//
//	test.insert(5);
//	test.insert(4);
//	test.insert(3);
//	test.insert(2);
//	test.insert(1);
//	test.insert(6);
//	test.insert(0);
//
//	for(int z: test)
//		cout<<z<<" ";
//	cout<<endl;
//
//	set<int>::value_compare vc = myset.value_comp();
//
//	if(myset.count(100))
//		cout<<"element found";
//	else
//		cout<<"not found";
//
//	cout<<endl;
//	return 0;
//}
//
//



//#include <windows.h>
//#include <atlbase.h>
//#include <urlmon.h>
//#include <stdlib.h>
//#include <Objbase.h>
//
//int main()
//{
//	DWORD dwZone;
//	HRESULT hres = E_FAIL;
//	CComPtr<IZoneIdentifier> spzi;
//	hres =  CoInitializeEx(
//					0,
//					COINIT_MULTITHREADED
//					);
//	if ( FAILED(hres) )
//	{
//		return ERROR_FUNCTION_FAILED;                  // Program has failed.
//	}
//
//
// spzi.CoCreateInstance(CLSID_PersistentZoneIdentifier);
//
//
// if (SUCCEEDED(CComQIPtr<IPersistFile>(spzi)->Load(L"C:\\Users\\Rohit.Khajindar\\Downloads\\MySQL-python-1.2.5.win32-py2.7.exe", STGM_READ)) &&
//	 SUCCEEDED(spzi->GetId(&dwZone)))
// {
//	printf("Zone identifier is %d\n", dwZone);
// }
// else
// {
//	printf("Couldn't get zone identifier (perhaps there isn't one)\n");
// }
//
// return 0;
//}

//#include<iostream>
//
//using namespace std;
//int main()
//{
//	int a = 3;
//	int b = 2;
//	int *!@is-legal;
//
//	b = a++;
//	cout<<++b;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	void Display()
//	{
//
//		cout<<"Base : Display"<<endl;
//	}
//
//};
//class Derived : public Base
//{
//public:
//	void Display()
//	{
//
//		cout<<"Derived : Display"<<endl;
//	}
//
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	(*bptr).Display();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	/*for(int x= 1;x<=6;x+=2)
//		cout<<x+(rand()%2);*/
//	int y = 10;
//	double x =0;
//	while(y>x)
//	{
//		++x;
//		--y;
//	}
//	cout<<x<<y;
//	return 0;
//
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	const int a;
//public:
//	Base(int num):a(num)
//	{}
//
//
//};
//
//int main()
//{
//	Base b(10);
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 3;
//	int b= 2;
//
//	cout<<++a * b++;
//
//	return 0;
//}

//#include<iostream>
//#include<map>
//
//
//using namespace std;
//
//int main()
//{
//	map<char ,int>mymap;
//
//	cout<<"Map size == "<<mymap.size()<<endl;
//	cout<<"Map Max_Size == "<<mymap.max_size()<<endl;
//
//	mymap.insert(pair<char,int>('Y',2));
//	mymap.insert(pair<char,int>('A',72));
//	mymap.insert(pair<char,int>('Z',82));
//	mymap.insert(pair<char,int>('B',2));
//	mymap.insert(pair<char,int>('E',2));
//	mymap.insert(pair<char,int>('Y',42));
//	mymap.insert(pair<char,int>('D',2));
//
//	map<char,int>::iterator it = mymap.begin();
//
//	while(it != mymap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//
//	//
//
//	mymap.emplace('G',444);
//	mymap.emplace('R',555);
//
//	for(auto a : mymap)
//		cout<<a.first<<" "<<a.second<<endl;
//	cout<<endl;
//
//	mymap.emplace_hint(mymap.begin(),'A',222);
//	mymap.emplace_hint(mymap.end(),'O',44);
//
//	for(auto b: mymap)
//		cout<<b.first<<" "<<b.second<<endl;
//	cout<<endl;
//	cout<<"Map element at A == "<<mymap.at('A')<<endl;
//
//	if(mymap.count('Z') > 0)
//		cout<<"Key found in map"<<endl;
//	else
//		cout<<"Key not found in map"<<endl;
//
//	map<char,int>::iterator ita = mymap.find('S');
//
//	if(ita != mymap.end())
//		mymap.erase(ita);
//	else
//		cout<<"Key not found "<<endl;
//
//	for(auto c: mymap)
//		cout<<c.first<<" "<<c.second<<endl;
//	cout<<endl;
//
//	mymap['Q'];
//	mymap['A'] = 2221;
//	mymap['I'] = 5441;
//	for(auto d: mymap)
//		cout<<d.first<<" "<<d.second<<endl;
//
//	cout<<endl;
//	pair<map<char,int>::iterator,map<char,int>::iterator>itc;
//	itc = mymap.equal_range('Y');
//
//	cout<<"Lower bound : ";
//	cout<<itc.first->first<<" "<<itc.first->second<<endl;
//	cout<<"Upper bound : ";
//	cout<<itc.second->first<<" "<<itc.second->second<<endl;
//
//	cout<<endl;
//	map<char,int>::key_compare kcomp = mymap.key_comp();
//	char highest = mymap.rbegin()->first;     // key value of last element
//
//	  std::map<char,int>::iterator itd = mymap.begin();
//	  do {
//			std::cout << itd->first << " => " << itd->second << '\n';
//	  } while ( kcomp((*itd++).first, highest) );
//
//	std::cout << '\n';
//
//	//map<char,int>::iterator itlow,itup;
//	//itlow=mymap.lower_bound ('Y');  // itlow points to b
//	//itup=mymap.upper_bound ('A');   // itup points to e (not d!)
//	//
//	//mymap.erase(itlow,itup);        // erases [itlow,itup)
//
//	//// print content:
//	//for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//	//std::cout << it->first << " => " << it->second << '\n';
//
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	multimap<int,char>mmap;
//
//	mmap.insert(pair<int,char>(1,'A'));
//	mmap.insert(pair<int,char>(11,'A'));
//	mmap.insert(pair<int,char>(9,'K'));
//	mmap.insert(pair<int,char>(34,'L'));
//	mmap.insert(pair<int,char>(2,'M'));
//	mmap.insert(pair<int,char>(8,'Q'));
//	mmap.insert(pair<int,char>(3,'H'));
//	mmap.insert(pair<int,char>(1,'A'));
//	mmap.insert(pair<int,char>(1,'Z'));
//
//	multimap<int,char>::iterator it = mmap.begin();
//
//	while(it != mmap.end())
//	{
//		cout<<it->first<<" "<<it->second<<endl;
//		it++;
//	}
//	cout<<endl;
//
//	pair<multimap<int,char>::iterator,multimap<int ,char>::iterator> ita;
//	ita = mmap.equal_range(9);
//
//	cout<<"lower bound : ";
//	cout<<ita.first->first<<" "<<ita.first->second<<endl;
//	cout<<"upper bound : ";
//	cout<<ita.second->first<<" "<<ita.second->second<<endl;
//
//	cout<<endl;
//
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	cout<<5%2<<endl;
//
//	/*int a = 5;
//	float b = 5.0;
//
//	if(a == b)
//		cout<<"Same"<<endl;
//	else
//		cout<<"Not Same"<<endl;*/
//
//
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int secondLargest(int arr[],int n)
//{
//	int max1 =0;
//	int max2 = 0;
//	int max3 = 0;
//	for(int i = 0;i<n;i++)
//	{
//		if(arr[i] > max1 )
//		{
//			max3 = max2;
//			max2 = max1;
//			max1 = arr[i];
//
//		}
//		else if(arr[i] > max2)
//		{
//			max3 = max2;
//			max2 = arr[i];
//		}
//		else if(arr[i] > max3)
//			max3 = arr[i];
//
//	}
//	cout<<"Second largest == "<<max2<<endl;
//	cout<<"Third largest == "<<max3<<endl;
//
//	return max2;
//
//
//}
//
//
//int main()
//{
//	int arr[] ={1,2,3,4,5,6,7};
//
//	int n = sizeof(arr)/sizeof(arr[0]);
//	cout<<"Array : ";
//	for(int i =0;i<n;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;
//	secondLargest(arr,n);
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//void func(char** str)
//{
//	char *temp = "Bye";
//	*str = temp;
//
//}
//
//int main()
//{
//	char *s = "Hello";
//	printf("%s\n", s);
//	func(&s);
//	printf("%s\n", s);
//	return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	int a;
//public:
//	Base(int num)
//	{
//		(*this).a = num;
//
//
//	}
//
//
//};

//#include<iostream>
//using namespace std;

//template<class T>
//T sum(T a , T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout<<sum(4,5)<<endl;
//	cout<<sum(4.0,5.0)<<endl;
//	//cout<<sum("Rohit","Khajindar")<<endl;
//	//cout<<sum('A','B')<<endl;
//
//
//
//	return 0;
//}
//
//template <class T, class U>
//U smaller(T a, U b) {
//  return (a < b ? a : b);
//}
//
//int main () {
//  int x=72;
//  double y=15.34;
//  cout << smaller(x, y) << endl;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int i = 5;
//	for(int i =0;i<7;i++){}
//
//	cout<<i<<endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 2;
//	--i;
//	cout<<i/2<<endl;
//
//	return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	volatile int i;
//
//};
//
//int main()
//{
//	Base b;
//	cout<<"Size of class == "<<sizeof(Base)<<endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//int main()
//{
//	char *str;
//	int len;
//	str = new char[100];
//
//	cout<<"Enter string == ";
//	cin>>str;
//
//	len = strlen(str);
//	cout<<"Reverse String == ";
//	for(int i = len ; i>=0; i--)
//	{
//		cout<<str[i];
//
//	}
//	cout<<endl;
//
//	return 0;
//}

//#include <iostream>
//class A {
//private:
//    int a;
//public:
//    A() { a=0; }
//    friend class B;     // Friend Class
//};
//
//class B {
//private:
//    int b;
//public:
//    void showA(A& x) {
//        // Since B is friend of A, it can access
//        // private members of A
//        std::cout << "A::a=" << x.a;
//    }
//};
//
//int main() {
//   A a;
//   B b;
//   b.showA(a);
//   return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	int a;
//	int b;
//public:
//	Base(int m = 30, int n = 40):a(m),b(n){}
//	friend void Display(Base b);
//
//};
//
//void Display(Base b1)
//{
//	cout<<"X == "<<b1.a<<endl;
//	cout<<"Y == "<<b1.b<<endl;
//
//}
//
//int main()
//{
//	Base b(10,20);
//	Display(b);
//
//
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//inline void Display()
//{
//	cout<<"Dipslay ()"<<endl;
//
//}
//
//int main()
//{
//	Display();
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int fact(int n)
//{
//	if(n < 0)
//		return -1;
//	if(n == 0)
//		return 1;
//	return (n * fact(n-1));
//}
//int main()
//{
//	int num;
//	int fc;
//
//	cout<<"Enter no. == ";
//	cin>>num;
//
//	fc = fact(num);
//	cout<<" Factorial of given no. == " <<fc<<endl;
//	return 0;
//}

#include<iostream>

using namespace std;

//void swap(int &m, int &n)
//{
//	int temp = m;
//	m = n;
//	n = temp;
//
//}

//void swap(int m, int n)
//{
//	int temp = m;
//	m = n;
//	n = temp;
//
//}

//void swap(int *m, int *n)
//{
//	int temp = *m;
//	*m = *n;
//	*n = temp;
//
//}
//
//int main()
//{
//	int a,b;
//
//	cout<<"Enter 2 nos.";
//	cin>>a>>b;
//
//	cout<<"Before Swap : ";
//	cout<<"A == "<<a<<" "<<"B == "<<b<<endl;
//
//	swap(&a,&b);
//
//	cout<<"After Swap : ";
//	cout<<"A == "<<a<<" "<<"B == "<<b<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num;
//	int cnt = 0;
//
//	cout<<"Enter num : ";
//	cin>>num;
//	while(num > 0)
//	{
//		num = num/10;
//		cnt++;
//	}
//	cout<<"Digits in num == "<<cnt<<endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num,next;
//	int f0 = 0;
//	int f1 = 1;
//
//	cout<<"Enter no. == ";
//	cin>>num;
//
//	for(int i =0; i<num; i++)
//	{
//		cout<<f0<<" ";
//		next = f0 + f1;
//		f0 = f1;
//		f1 = next;
//	}
//	return 0;
//}

//#include<iostream>
//
//
//int main()
//{
//int arm=0,a,b,c,d,no;
//
//cout<<"Enter any num: ";
// cin>>no;
//d=no;
//while(no>0)
//{
//a=no%10;
//no=no/10;
//arm=arm+a*a*a;
//}
//if(arm==d)
//{
//cout<<"Armstrong";
//}
//else
//{
//cout<<"not Armstrong";
//}
//
//return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//void main()
//{
//int a,no,b,temp=0;
//
//cout<<"Enter any num: ";
//cin>>no;
//b=no;
//while(no>0)
//{
//a=no%10;
//no=no/10;
//temp=temp*10+a;
//}
//if(temp==b)
//{
//cout<<"Palindrome";
//}
//else
//{
//cout<<"Not Palindrome";
//}
//
//}

//// Program to check if a given linked list of strings
//// form a palindrome
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
///* Link list node */
//struct Node
//{
//    string data;
//    Node* next;
//};
//
//// A utility function to check if str is palindrome
//// or not
//bool isPalindromeUtil(string str)
//{
//    int length = str.length();
//
//    // Match characters from beginning and
//    // end.
//    for (int i=0; i<length; i++)
//        if (str[i] != str[length-i-1])
//            return false;
//
//    return true;
//}
//
//// Returns true if string formed by linked
//// list is palindrome
//bool isPalindrome(Node *node)
//{
//    // Append all nodes to form a string
//    string str = "";
//    while (node != NULL)
//    {
//        str.append(node->data);
//        node = node->next;
//    }
//
//    // Check if the formed string is palindrome
//    return isPalindromeUtil(str);
//}
//
//// A utility function to print a given linked list
//void printList(Node *node)
//{
//    while (node != NULL)
//    {
//        cout << node->data << " -> ";
//        node = node->next;
//    }
//    printf("NULL\n");
//}
//
///* Function to create a new node with given data */
//Node *newNode(const char *str)
//{
//    Node *new_node = new Node;
//    new_node->data = str;
//    new_node->next = NULL;
//    return new_node;
//}
//
///* Driver program to test above function*/
//int main()
//{
//    Node *head = newNode("a");
//    head->next = newNode("bc");
//    head->next->next = newNode("d");
//    head->next->next->next = newNode("dcb");
//    head->next->next->next->next = newNode("a");
//
//    isPalindrome(head)? printf("true\n"):
//                        printf("false\n");
//
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num,pow;
//	int Power = 1;
//	cout<<"Enter no. and power == ";
//	cin>>num>>pow;
//	cout<<endl;
//
//	for(int i = pow;i>0;i--)
//	{
//		Power = Power * num;
//	}
//	cout<<"Power of number == "<<Power<<endl;
//
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//#include<conio.h>
//
//
//using namespace std;
//
//struct node
//{
//	int data;
//	struct node *next;
//}*start = NULL;
//
//void createLL()
//{
//	char ch;
//	do
//	{
//		struct node *newNode, *current;
//		newNode = (struct node *) malloc (sizeof(struct node));
//
//		printf("\n Enter Data = ");
//		scanf("%d",&newNode->data);
//		newNode->next = NULL;
//
//		if(start == NULL)
//		{
//			start = newNode;
//			current = newNode;
//		}
//		else
//		{
//			current->next = newNode;
//			current = newNode;
//		}
//		 printf("nDo you want to creat another : ");
//		ch=getche();
//	}while(ch != 'n');
//
//}
//
//void Display()
//{
//	struct node *ptr = start;
//	while(ptr!= NULL)
//	{
//		printf("%d =>",ptr->data);
//		ptr = ptr->next;
//	}
//	  printf("NULL");
//}
//
//int main()
//{
//	createLL();
//	Display();
//	return 0;
//}

//#include<stdio.h>
//#include<conio.h>
//
////-------------------------------------------------
//struct node
//{
//int data;
//struct node *next;
//}*start=NULL;
////------------------------------------------------------------
//
//void create()
//{
//char ch;
// do
// {
//  struct node *new_node,*current;
//
//  new_node=(struct node *)malloc(sizeof(struct node));
//
//  printf("\n Enter the data : ");
//  scanf("%d",&new_node->data);
//  new_node->next=NULL;
//
//  if(start==NULL)
//  {
//	  start=new_node;
//	 // current = start;
//  }
//  else
//  {
//	 current = start;
//	 while(current->next != NULL)
//	 {
//		current = current->next;
//	 }
//	  current->next = new_node;
//  }
//
// printf("\n Do you want to creat another : ");
// ch=getche();
// }while(ch!='n');
//}
////------------------------------------------------------------------
//
//void display()
//{
//struct node *new_node;
// printf("\n The Linked List : ");
// new_node=start;
// while(new_node!=NULL)
//   {
//	   printf("%d=>",new_node->data);
//	   new_node=new_node->next;
//   }
//  printf("NULL");
//}
////----------------------------------------------------
//void main()
//{
//create();
//display();
//}

//#include<iostream>
//#include<stdio.h>
//
//struct node
//{
//	int data;
//	struct node *link;
//}*head = NULL;
//
//void isPalin(struct node *head,int num)
//{
//	int cnt =0;
//	struct node *first, *last;
//
//	while(cnt != num/2)
//	{
//		first = last = head;
//
//		for(int i =0; i<cnt; i++)
//		{
//			first = first->link;
//
//		}
//		for(int j =0; j<num - (cnt +1); j++)
//		{
//			last = last->link;
//		}
//
//		if(first->data != last->data)
//		{
//			cout<<"Not Palindrome"<<endl;
//			return ;
//		}
//		else
//		{
//			cnt++;
//		}
//		cout<<"palindrome"<<endl;
//	}
//}
//
//
//void Create()
//{
//	struct node *newnode,*current;
//
//	int num;
//
//	cout<<"Size of linked list : ";
//	cin>>num;
//	cout<<endl;
//	for(int i = 0;i<num;i++)
//	{
//		cout<<"Enter data : ";
//		newnode = (struct node *) malloc (sizeof(struct node));
//		cin>>newnode->data;
//		newnode->link = NULL;
//
//		if(head == NULL)
//		{
//			head = newnode;
//		}
//		else
//		{
//			current = head;
//			while(current->link != NULL)
//			{
//				current = current->link;
//			}
//			current->link = newnode;
//		}
//
//	}//end of for
//
//	isPalin(head,num);
//
//}//end of create
//
//void Reverse()
//{
//	struct node *ptr,*next,*prev;
//	ptr= head;
//	prev = NULL;
//
//	while(ptr != NULL)
//	{
//		next = ptr->link;
//		ptr->link = prev;
//		prev = ptr;
//		ptr = next;
//	}
//	head = prev;
//}
//
//
//void Display()
//{
//	struct node *ptr;
//	ptr = head;
//
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr= ptr->link;
//	}
//
//	cout<<endl;
//
//}
//
//int main()
//{
//	cout<<"Create LL : "<<endl;
//	Create();
//	cout<<"Display LL : "<<endl;
//	Display();
//	cout<<"Reverse LL : "<<endl;
//	Reverse();
//	Display();
//
//}



//#include<iostream>
//#include<stdio.h>
//#include<string>
//
//
//struct node
//{
//	string data;
//	struct node *link;
//}*head = NULL;
//
//string tochekpalindrome(struct node *start)
//{
//	string str;
//
//	while( start != NULL)
//	{
//		str.append(start->data);
//
//		start = start->link;
//	}
//	cout<<"String == "<<str.c_str();
//	return str;
//}
//
//void Create()
//{
//	struct node *newnode,*current;
//
//	int num;
//	newnode = (struct node *) malloc (sizeof(struct node));
//	cout<<"Size of linked list : ";
//	cin>>num;
//	newnode->link = NULL;
//	cout<<endl;
//	for(int i = 0;i<num;i++)
//	{
//		if(head == NULL)
//		{
//		cout<<"Enter data : ";    head = newnode;
//		}
//		else
//		{
//			current = head;
//			while(current->link != NULL)
//			{
//				current = current->link;
//			}
//			current->link = newnode;
//		}
//
//	}//end of for
//
//	tochekpalindrome(head);
//
//}//end of create
//
//void Display()
//{
//	struct node *ptr;
//	ptr = head;
//
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr= ptr->link;
//	}
//
//	cout<<endl;
//
//}
//
//int main()
//{
//	cout<<"Create LL : "<<endl;
//	Create();
//	cout<<"Display LL : "<<endl;
//	Display();
//
//	Display();
//
//}


//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	char *str1;
//	int cnt = 0;
//	str1 = (char *) malloc(100);
//
//	cout<<"Enter String1 : ";
//	cin>>str1;
//	cout<<endl;
//	int len = strlen(str1);
//	cout<<"Vowels in string == ";
//
//	for(int i = 0;i<len; i++)
//	{
//		if(str1[i] == 'A' || str1[i] == 'E' ||str1[i] == 'I' ||str1[i] == 'O' ||
//			str1[i] == 'U' ||str1[i] == 'a' ||str1[i] == 'e' ||str1[i] == 'i' ||
//			str1[i] == 'o' ||str1[i] == 'u' )
//		{
//			cout<<str1[i]<<" ";
//			cnt++;
//		}
//	}
//	cout<<endl;
//
//	cout<<"Vowels count == "<<cnt<<endl;
//
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int factorial(int num)
//{
//	int fact = 1;
//	if(num < 1)
//		return fact;
//	fact = num*factorial(num-1);
//
//	return fact;
//
//}
//
//int main()
//{
//	int num;
//	int tot;
//	cout<<"Enter no. ";
//	cin>>num;
//
//	tot = factorial(num);
//	cout<<"Factorial of given no. == "<<tot<<endl;
//
//}
//


//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	int fact = 1;
//	cout<<"Enter no. : ";
//	cin>>n;
//
//	for(int i =1 ;i<= n; i++)
//	{
//		fact = fact * i;
//
//	}
//
//	cout<<"Factorial of given no. : "<<fact<<endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int year;
//	cout<<"Enter year : ";
//	cin>>year;
//
//	if(year%4 == 0)
//		cout<<"Leap year";
//	else
//		cout<<"Not a Leap year";
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int arr[]={4,8,9,7,5,6,1};
//	int n = sizeof(arr)/sizeof(arr[0]);
//
//	cout<<"Array element : ";
//	for(int i = 0; i<n;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;
//
//	cout<<"Reverse Array element : ";
//	for(int i = n-1; i>=0;i--)
//		cout<<arr[i]<<" ";
//	cout<<endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cout<<"Enter no. of rows : ";
//	cin>>n;
//
//	for(int i =0; i<=n; i++)
//	{
//		for(int j= n-1; j>=i; j--)
//		{
//		cout<<" ";
//		}
//		for(int k=1; k<=(2*i-1); k++)
//		{
//		cout<<"*";
//		}
//		cout<<endl;
//
//	}
//
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num;
//	cout<<"Enter no. of rows : ";
//	cin>>num;
//	cout<<endl;
//
//	for(int i = 1;i<=num;i++)
//	{
//		for(int j = 1; j<=i; j++)
//		{
//			cout<<i;
//		}
//		cout<<endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int num;
//	int k = 1;
//	cout<<"Enter no. of rows : ";
//	cin>>num;
//	cout<<endl;
//
//	for(int i = 1;i<=num;i++)
//	{
//		for(int j = i; j<=num; j++)
//		{
//			cout<<k;
//
//		}
//		cout<<endl;
//		k++;
//	}
//
//	return 0;
//}
//
///* This code is adopted from the solution given
//   @ http://effprog.blogspot.com/2011/01/spiral-printing-of-two-dimensional.html */
//
//#include <stdio.h>
//#define R 3
//#define C 6
//
//void spiralPrint(int m, int n, int a[R][C])
//{
//    int i, k = 0, l = 0;
//
//    /*  k - starting row index
//        m - ending row index
//        l - starting column index
//        n - ending column index
//        i - iterator
//    */
//
//    while (k < m && l < n)
//    {
//        /* Print the first row from the remaining rows */
//        for (i = l; i < n; ++i)
//        {
//            printf("%d ", a[k][i]);
//        }
//        k++;
//
//        /* Print the last column from the remaining columns */
//        for (i = k; i < m; ++i)
//        {
//            printf("%d ", a[i][n-1]);
//        }
//        n--;
//
//        /* Print the last row from the remaining rows */
//        if ( k < m)
//        {
//            for (i = n-1; i >= l; --i)
//            {
//                printf("%d ", a[m-1][i]);
//            }
//            m--;
//        }
//
//        /* Print the first column from the remaining columns */
//        if (l < n)
//        {
//            for (i = m-1; i >= k; --i)
//            {
//                printf("%d ", a[i][l]);
//            }
//            l++;
//        }
//    }
//}
//
///* Driver program to test above functions */
//int main()
//{
//    int a[R][C] = { {1,  2,  3,  4,  5,  6},
//        {7,  8,  9,  10, 11, 12},
//        {13, 14, 15, 16, 17, 18}
//    };
//
//    spiralPrint(R, C, a);
//    return 0;
//}


//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//struct node
//{
//	int data;
//	struct node *link;
//
//}*head = NULL;
//
//void CreateLL()
//{
//	int num, item;
//	struct node *temp,*current;
//	cout<<"Enter no. of nodes : ";
//	cin>>num;
//	cout<<endl;
//	for(int i=0;i<num;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>item;
//		cout<<endl;
//		temp = (struct node*) malloc (sizeof(struct node));
//		temp->data = item;
//		temp->link = NULL;
//		if( head == NULL)
//		{
//			head = temp;
//			current = temp;
//		}
//		else
//		{
//			while(current->link != NULL )
//			{
//				current = current->link;
//			}
//			current->link = temp;
//			current = temp;
//		}
//	}
//
//}
//
//void DisplayLL()
//{
//	struct node *ptr;
//	ptr = head;
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr = ptr->link;
//	}
//
//
//}
//
//void RemoveDupLL()
//{
//	struct node *ptr1, *ptr2, *dup;
//	ptr1 = head;
//
//	while(ptr1 != NULL && ptr1->link != NULL)
//	{
//		ptr2 = ptr1;
//		while(ptr2->link != NULL)
//		{
//			if(ptr1->data == ptr2->link->data)
//			{
//				dup = ptr2->link;
//				ptr2->link = ptr2->link->link;
//				free(dup);
//			}
//			else
//				ptr2 = ptr2->link;
//		}
//		ptr1 = ptr1->link;
//	}
//
//}
//
//void DeleteLL(int num)
//{
//	struct node *ptr,*temp,*lastPtr;
//	//delete fisrt
//	if(head->data == num)
//	{
//		temp = head;
//		head = head->link;
//		free(temp);
//
//	}
//	//delete in between
//	ptr = head;
//	while(ptr->link != NULL)
//	{
//		if(ptr->link->data == num)
//		{
//			temp = ptr->link;
//			ptr->link = temp->link;
//			free(temp);
//		}
//		ptr= ptr->link;
//	}
//
//	//delete last node
//	/*ptr = head;
//	while(ptr->link->link != NULL)
//		ptr= ptr->link;
//	if(ptr->link->data == num)
//	{
//		temp = ptr->link;
//		ptr->link = temp->link;
//		free(temp);
//	}*/
//
//
//
//	//if(ptr->link->link == NULL)
//	//{
//	// if(ptr->link->data == num)
//	// {
//	//   ptr->link = NULL;
//	//   /*temp = ptr->link;
//	//   ptr->link = NULL;
//	//   free(temp);*/
//	// }
//	//}
//
//}
//
//void ReverseLL()
//{
//	struct node *ptr,*prev,*next;
//	ptr = head;
//	prev = NULL;
//	while(ptr != NULL)
//	{
//		next = ptr->link;
//		ptr->link = prev;
//		prev = ptr;
//		ptr = next;
//	}
//	head = prev;
//}
//
//int main()
//{
//	cout<<"CreatLL : "<<endl;
//	CreateLL();
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//	cout<<"RemoveDupLL : ";
//	RemoveDupLL();
//	DisplayLL();
//	cout<<endl;
//	cout<<"DeleteLL : ";
//	DeleteLL(0);
//	DisplayLL();
//	cout<<endl;
//	cout<<"ReverseLL : ";
//	ReverseLL();
//	DisplayLL();
//	cout<<endl;
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	char *str;
//	int len;
//
//public:
//	Base(char *tmp)
//	{
//		len = strlen(tmp);
//		str = new char[len +1] ;
//		strcpy(str,tmp);
//		cout<<"Parametrised : str == "<<str<<endl;
//
//	}
//	Base(const Base &b)
//	{
//
//	}
//
//
//};


//#include<iostream>
//#include<stdio.h>
//
//struct node{
//	int data;
//	struct node *next;
//}*start = NULL;
//
//
//void CreateLL()
//{
//	int num,item;
//	struct node *ptr,*current;
//	cout<<"\n Enter no. of Nodes : ";
//	cin>>num;
//	cout<<endl;
//	for(int i =0;i<num;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>item;
//		cout<<endl;
//		ptr = (struct node *)malloc(sizeof(struct node));
//		ptr->data = item;
//		ptr->next = NULL;
//
//		if(start == NULL)
//		{
//			start = ptr;
//			current = ptr;
//		}
//		else
//		{
//			while(current->next != NULL)
//			{
//				current = current->next;
//			}
//			current->next = ptr;
//			current = ptr;
//		}
//
//	}
//}
//
//void AddAtBegLL(int item)
//{
//	struct node *temp;
//	temp = (struct node*) malloc (sizeof(struct node));
//	temp->data = item;
//
//	if(start == NULL)
//	{
//		start = temp;
//		start->next = NULL;
//	}
//	else
//	{
//		temp->next = start;
//		start = temp;
//
//	}
//
//
//}
//
//void AddAtEndLL(int item)
//{
//	struct node *temp,*ptr;
//	temp = (struct node *) malloc (sizeof(struct node));
//	temp->data = item;
//	temp->next = NULL;
//	ptr = start;
//	if(start == NULL)
//	{
//		start = temp;
//		return;
//	}
//	else
//	{
//		while(ptr->next != NULL)
//			ptr = ptr->next;
//		ptr->next = temp;
//		ptr = temp;
//	}
//
//}
//
//void NodeAfterLL(int pos, int item)
//{
//	int i;
//    struct node *temp,*ptr2,*ptr1;
//    ptr1=start;
//    for(i=1;i<2;i++)
//    {
//		ptr2=ptr1;
//		ptr1=ptr1->next;
//    }
//    temp=(struct node *)malloc(sizeof(struct node));
//    temp->data=item;
//    ptr2->next=temp;
//    ptr2=temp;
//    ptr2->next=ptr1;
//
//}
//
//void DisplayLL()
//{
//	struct node *ptr;
//	ptr = start;
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr = ptr->next;
//	}
//
//}
//
//
//
//int main()
//{
//	cout<<"CreateLL : ";
//	CreateLL();
//	cout<<endl;
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//	cout<<"AddAtBegLL : ";
//	AddAtBegLL(9);
//	DisplayLL();
//	cout<<endl;
//	cout<<"AddAtEndLL : ";
//	AddAtEndLL(11);
//	DisplayLL();
//	cout<<endl;
//	cout<<"NodeAfterLL : ";
//	NodeAfterLL(2,20);
//	DisplayLL();
//
//	cout<<endl;
//	return 0;
//}


//#include<windows.h>
//
//#define ZONE_IDENTIFIER     L":Zone.Identifier"
//
//int main()
//{
//	HANDLE hHandle = NULL;
//	WCHAR wszPath[MAX_PATH] = L"E:\\ATP-BDS-Epics.xlsx";//L"C:\\Users\\Rohit.Khajindar\\Downloads\\VirtualBox-5.1.14-112924-Win.exe";
//
//	wcscat(wszPath,ZONE_IDENTIFIER);
//	::MessageBox(NULL,wszPath,L"wszPath",MB_OK | MB_TOPMOST);
//	hHandle =  CreateFile(
//					wszPath,
//					GENERIC_READ,
//					FILE_SHARE_READ | FILE_SHARE_WRITE,
//					NULL,
//					OPEN_EXISTING,
//					FILE_ATTRIBUTE_NORMAL,
//					NULL
//					);
//
//	if(hHandle == INVALID_HANDLE_VALUE)
//	{
//		::MessageBox(NULL,L"File Create Fail.",L"TRUE",MB_OK | MB_TOPMOST);
//	}
//	else
//	{
//		::MessageBox(NULL,L"File Create Success.",L"TRUE",MB_OK | MB_TOPMOST);
//	}
//
//
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//int main()
//{
//	char *ptr;
//	//char ptr[6];
//	ptr = (char *) malloc (100);
//	strcpy(ptr,"Hello");
//	cout<<"Ptr == "<<ptr<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	for(int c = 0 ;c<256;c++)
//	{
//		cout<<c<<endl;
//	}
//	return 0;
//}

//find sum of array elements
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int arr[] = {15,5,10,10,3,4,5,5,6,13,7,3,17};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	int sum = 20;
//	int k;
//	int Total;
//
//	for(int i =0; i<n;i++)
//	{
//		k = 1;
//		k = k + i;
//		while(k<n)
//		{
//			Total = 0;
//			Total = arr[i] + arr[k];
//			if(sum == Total)
//			{
//				cout<<" Array element index "<<i <<" : "<<arr[i]<<" AND"<<" Array element index "<<k<<" : "<<arr[k]<<endl;
//			}
//			k++;
//		}
//	}
//
//
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//struct node{
//	int data;
//	struct node *next;
//}*head = NULL;
//
//void CreateLL()
//{
//	struct node *tmp,*current;
//	int num,item;
//
//	cout<<" \n Enter no. of nodes : ";
//	cin>>num;
//	cout<<endl;
//
//	for(int i =0; i<num;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>item;
//		cout<<endl;
//		tmp = (struct node*)malloc (sizeof(struct node));
//		tmp->data = item;
//		tmp->next = NULL;
//
//		if(head == NULL)
//		{
//			head = tmp;
//			current = tmp;
//		}
//		else
//		{
//			while(current->next != NULL)
//			{
//				current = current->next;
//			}
//			current->next = tmp;
//			current = tmp;
//		}
//	}//end of for
//
//}//end of CreateLL
//
//
//void DisplayLL()
//{
//	struct node *ptr;
//	ptr = head;
//
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr = ptr->next;
//	}
//}
//
//void ReverseLL()
//{
//	struct node *ptr,*prev,*link;
//	ptr = head;
//	prev = NULL;
//
//	while(ptr != NULL)
//	{
//		link = ptr->next;
//		ptr->next = prev;
//		prev = ptr;
//		ptr = link;
//	}
//	head = prev;
//
//}
//
//int main()
//{
//	cout<<"CreateLL : ";
//	CreateLL();
//	cout<<endl;
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//	cout<<"ReverseLL : ";
//	ReverseLL();
//	DisplayLL();
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	~Base()
//	{
//		cout<<'A'<<endl;
//	}
//};
//
//int main()
//{
//	Base b;
//	b.~Base();
//
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	//char str[] = "Rohit";
//	char *str = "Rohit";
//
//	cout<<str[0]<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int function(double x)
//{
//
//
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////void removeelement(vector <int >&vect,int elem)
////{
////  vect.erase(remove(vect.begin(),vect.end(),elem),vect.end());
////  vect.erase(std::remove(vect.begin(), vect.end(), elem), vect.end());
////}
//
//
//int main()
//{
//	vector<int>myvect;
//
//	myvect.push_back(10);
//	myvect.push_back(98);
//	myvect.push_back(45);
//	myvect.push_back(7);
//	myvect.push_back(63);
//	myvect.push_back(5);
//	myvect.push_back(4);
//	myvect.push_back(10);
//	myvect.push_back(88);
//
//	cout<<"size of vector == "<<myvect.size()<<endl;
//	cout<<"Max_size of vector == "<<myvect.max_size()<<endl;
//	cout<<"Capacity of vector == "<<myvect.capacity()<<endl;
//	myvect.reserve(100);
//	cout<<"Capacity of vector == "<<myvect.capacity()<<endl;
//
//
//	vector<int>::iterator it = myvect.begin();
//
//	while(it != myvect.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	myvect.pop_back();
//	myvect.pop_back();
//	cout<<"size of vector == "<<myvect.size()<<endl;
//
//	for(int a: myvect)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	myvect.emplace(myvect.begin(),222);
//	myvect.emplace(myvect.end(),21);
//
//	for(int b : myvect)
//	{
//		cout<<b<<" ";
//	}
//	cout<<endl;
//
//	myvect.emplace_back(2133);
//	for(int c: myvect)
//	{
//		cout<<c<<" ";
//	}
//	cout<<endl;
//
//	vector<int>tempvect;
//
//	tempvect = myvect;
//	for(int d : tempvect)
//	{
//		cout<<d<<" ";
//	}
//	cout<<endl;
//
//	tempvect.pop_back();
//	tempvect.pop_back();
//
//
//	tempvect.swap(myvect);
//	//myvect.swap(tempvect);
//	for(int e : myvect)
//	{
//		cout<<e<<" ";
//	}
//	cout<<endl;
//
//	/*vector<int>::iterator ita = myvect.begin();
//
//	while(it != myvect.end())
//	{
//		if(*it > 100 )
//		{
//			it = myvect.erase(it);
//		}
//		else
//			it++;
//	}*/
//
//	//removeelement(myvect,10);
//
//	vector<int>temp;
//
//	temp.assign(5,100);
//
//	for(int f : temp)
//	{
//		cout<<f<<" ";
//	}
//	cout<<endl;
//
//	cout<<"Value at 4th position == "<<myvect.at(4)<<endl;
//
//	cout<<"Element at 5th position == "<<myvect[5]<<endl;
//
//	myvect.resize(10);
//
//	for(int g : myvect)
//	{
//		cout<<g<<" ";
//	}
//	cout<<endl;
//
//	myvect.resize(7);
//
//	myvect.shrink_to_fit();
//
//	for(int h : myvect)
//	{
//		cout<<h<<" ";
//	}
//	cout<<endl;
//
//	cout<<"Vector capacity == "<<myvect.capacity()<<endl;
//
//	myvect.insert(myvect.begin(),20);
//	myvect.insert(myvect.end(),32);
//
//	for(int j : myvect)
//	{
//		cout<<j<<" ";
//	}
//	cout<<endl;
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//
//void removeAllMatchingElements_nonEfficient(std::vector<int> & vec, int elem)
//{
//   std::vector<int>::iterator it = vec.begin();
//   while(it != vec.end())
//   {
//     if(*it == elem)
//     {
//        it = vec.erase(it);
//     }
//     else
//        it++;
//  }
//}
//
//void removeAllMatchingElements_Efficient(std::vector<int> & vec, int elem)
//{
//    vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
//}
//
//void displayVector(std::vector<int> & vec)
//{
//   std::vector<int>::iterator it = vec.begin();
//   while(it != vec.end())
//       std::cout<<(*it++)<<" ";
//   std::cout<<std::endl;
//}
//int main()
//{
//   int arr[10] = {1,2,5,4,5,1,5,7,8,9};
//
//   std::vector<int> vec(arr , arr + 10);
//   removeAllMatchingElements_nonEfficient(vec, 5);
//   displayVector(vec);
//
//   std::vector<int> vec2(arr , arr + 10);
//   removeAllMatchingElements_Efficient(vec2, 5);
//   displayVector(vec2);
//
//   return 0;
//}


//#include<iostream>
//#include<list>
//
//using namespace std;
//
//int main()
//{
//	list<int>mylist;
//
//	mylist.push_back(10);
//	mylist.push_back(8);
//	mylist.push_back(7);
//	mylist.push_back(1);
//	mylist.push_back(2);
//	mylist.push_back(77);
//	mylist.push_front(7);
//	mylist.push_front(17);
//	mylist.push_front(55);
//	mylist.push_front(88);
//
//	list<int>::iterator it = mylist.begin();
//
//	while(it != mylist.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	mylist.pop_back();
//	mylist.pop_front();
//
//	for(int a : mylist)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	mylist.emplace(mylist.begin(),2222);
//	mylist.emplace(mylist.end(),332);
//
//	for(int b : mylist)
//	{
//		cout<<b<<" ";
//	}
//	cout<<endl;
//
//	mylist.emplace_back(550);
//	mylist.emplace_front(551);
//
//	for(int c: mylist)
//	{
//		cout<<c<<" ";
//	}
//	cout<<endl;
//
//	/*list<int>tmplist;
//
//	list<int>::iterator ita = mylist.begin();
//
//	tmplist.splice(mylist.begin(),mylist.end());
//
//	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());*/
//
//	mylist.remove(7);
//
//	for(int d : mylist)
//	{
//		cout<<d<<" ";
//	}
//	cout<<endl;
//
//	mylist.remove_if([](const int &val)
//		{
//			if(val > 100)
//				return true;
//			else
//				return false;
//		});
//
//	for(int e: mylist)
//	{
//		cout<<e<<" ";
//	}
//	cout<<endl;
//
//	mylist.reverse();
//
//	for(int f : mylist)
//	{
//		cout<<f<<" ";
//	}
//	cout<<endl;
//
//	mylist.push_back(7);
//	mylist.push_back(4);
//	mylist.push_back(4);
//	mylist.push_front(1);
//	mylist.push_front(9);
//	mylist.push_back(7);
//	mylist.sort();
//	mylist.unique();
//
//	for(int g : mylist)
//	{
//		cout<<g<<" ";
//	}
//	cout<<endl;
//
//
//	list<int>dlist;
//
//	dlist.assign(7,100);
//	for(int h : dlist)
//	{
//		cout<<h<<" ";
//	}
//	cout<<endl;
//
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	cout<<"Num == "<<10/6<<endl;
//
//	return 0;
//}


//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//struct node
//{
//	int data;
//	struct node *next;
//}*head = NULL;
//
//void CreateLL()
//{
//	int num,item;
//	struct node *temp,*current;
//	cout<<"Enter no. of nodes : ";
//	cin>>num;
//	cout<<endl;
//	for(int i = 0;i<num;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>item;
//		temp = (struct node*) malloc (sizeof(struct node));
//		temp->data = item;
//		temp->next = NULL;
//		if(NULL == head)
//		{
//			head = temp;
//			current = temp;
//		}
//		else
//		{
//			while(current->next != NULL)
//			{
//				current = current->next;
//			}
//				current->next = temp;
//				current = temp;
//		}
//	}
//}
//
//void DisplayLL()
//{
//	struct node *ptr;
//	ptr = head;
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr = ptr->next;
//	}
//}
//
//void ReverseLL()
//{
//	struct node *ptr,*prev,*link;
//	ptr = head;
//	prev = NULL;
//	while(ptr != NULL)
//	{
//		link = ptr->next;
//		ptr->next = prev;
//		prev = ptr;
//		ptr = link;
//	}
//	head = prev;
//}
//
//int main()
//{
//	cout<<"\n CreateLL : \n";
//	CreateLL();
//	cout<<endl;
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//	cout<<"ReverseLL : ";
//	ReverseLL();
//	DisplayLL();
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int i = 15;
//	for(int i =0;i<10;i++);
//	cout<<i<<endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	/*int x =5, y =2;
//	double result =  x%y;
//	cout<<result<<endl;*/
//
//	/*int *p = 0,x = 1;
//	*p = &x;
//	cout<<p<<endl;*/
//
//	cout<<38/5<<endl;
//	cout<<38.0/5<<endl;
//
//
//
//	return 0;
//}

//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//class Base
//{
//	static int cnt;
//public:
//	Base()
//	{
//		cout<<"Constrcutor "<<cnt<<endl;
//		cnt++;
//	}
//
//	~Base()
//	{
//		cnt--;
//		cout<<"Destrcutor "<<cnt<<endl;
//	}
//};
//int Base::cnt = 1;
//
//int main()
//{
//	Base * b = new Base[5];
//
//	shared_ptr<int>p1 (new int[5]);
//	delete []b;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		cout<<"Constructor call."<<endl;
//	}
//	void *operator new(size_t num)
//	{
//		cout<<"Operator new call."<<endl;
//		return malloc(num);
//	}
//
//	void operator delete(void * ptr)
//	{
//		cout<<"Delete operator call."<<endl;
//		free(ptr);
//	}
//	~Base()
//	{
//		cout<<"Destructor call."<<endl;
//	}
//};
//
//int main()
//{
//	Base *b = new Base();
//
//	delete b;
//
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	mutable int num;
//public:
//
//	Base(int a):num(a)
//	{}
//	 void Show()const
//	{
//		num = 20;
//		cout<<"num =="<<num<<endl;
//	}
//};
//
//int main()
//{
//	Base b(10);
//	b.Show();
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Show()
//	{
//		cout<<"Base : Show"<<endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	void Display()
//	{
//		cout<<"Derived : Display"<<endl;
//	}
//
//};
//
//int main()
//{
//	Base * b = new Derived();
//	b->Show();
//	Derived *d = dynamic_cast<Derived *> (b);
//	d->Display();
//	d->Show();
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//	char *name;
//	int len;
//public:
//	Base()
//	{
//		name = nullptr;
//		len = 0;
//	}
//	Base(char *tmp)
//	{
//		len = strlen(tmp);
//		name = new char[len +1];
//		strcpy(name,tmp);
//		cout<<"Constructor == "<<name<<endl;
//	}
//
//	/*Base(const Base &b)
//	{
//		len = strlen(b.name);
//		name = new char[len +1];
//		strcpy(name,b.name);
//		cout<<"Copy Constructor == "<<name<<endl;
//	}*/
//
//	~Base()
//	{
//		cout<<"Destructor "<<endl;
//		if( strlen(name) != 0)
//		{
//			delete name;
//		}
//	}
//
//};
//
//int main()
//{
//	char* str1 = "Rohit";
//	char* str2 = "Khajindar" ;
//
//	Base b1(str1);
//	Base b2 = b1;
//	//Base b3(str2);
//	//Base b4(b3);
//
//	//delete str1, str2;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//void display(int a)
//{
//	cout<<a<<" ";
//}
//
//int main()
//{
//	int arr[]={1,4,5,89,8,99};
//	int len = sizeof(arr)/sizeof(arr[0]);
//
//	for_each(arr,arr + len,&display);
//	cout<<endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int b = 20;
//	auto func = [&a,&b] () mutable
//	{
//		cout<<"a == "<<a<<endl;
//		cout<<"b == "<<b<<endl;
//		a = 30;
//		b = 40;
//		cout<<"a == "<<a<<endl;
//		cout<<"b == "<<b<<endl;
//	};
//	func();
//
//	cout<<"a == "<<a<<endl;
//	cout<<"b == "<<b<<endl;
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//class OddCounter
//{
//	// tracks the count of odd numbers encountered
//	int mCounter;
//public:
//
//	OddCounter(int a):mCounter(a)
//	{}
//	int getCount()
//	{
//		return mCounter;
//	}
//	void update(std::vector<int> & vec)
//	{
//		// Traverse the vector and increment mCounter if element is odd
//		// this is captured by value inside lambda
//		std::for_each(vec.begin(), vec.end(), [this](int element){
//			if(element % 2)
//				mCounter++; // Accessing member variable from outer scope
//		});
//	}
//};
//
//
//int main(int argc, char **argv)
//{
//	std::vector<int> vec ;
//	vec.push_back(6);
//	vec.push_back(3);
//	vec.push_back(2);
//	vec.push_back(1);
//	vec.push_back(8);
//	vec.push_back(9);
//	vec.push_back(0);
//	vec.push_back(2);
//	vec.push_back(3);
//	vec.push_back(9);
//	vec.push_back(7);
//
//
//
//	OddCounter counterObj(10);
//
//	//Passing the vector to OddCounter object
//	counterObj.update(vec);
//
//	int count = counterObj.getCount();
//
//	std::cout<<"Counter = "<<count<<std::endl;
//	return 0;
//}

//stack

//#include<iostream>
//#define MAX_SIZE 10
//int Stack_Arr[MAX_SIZE];
//int top = -1;
//
//using namespace std;
//int isFull()
//{
//	if(MAX_SIZE == top)
//	{
//		cout<<"Stack Full."<<endl;
//		return 0;
//	}
//}
//
//int isEmpty()
//{
//	if(MAX_SIZE == -1)
//	{
//		cout<<"Stack Empty."<<endl;
//		return 0;
//	}
//	else
//		return 1;
//}
//
//void Push()
//{
//	int num;
//	if(isFull == 0)
//		return;
//
//	for(int i = 0 ;i<MAX_SIZE;i++)
//	{
//		cout<<"Enter no. : ";
//		cin>>num;
//		cout<<endl;
//
//		top = top +1;
//		Stack_Arr[top] = num;
//	}
//}
//
//void Display()
//{
//	if(isEmpty == 0)
//		return;
//
//	for(int i = top;i>=0;i--)
//	{
//		cout<<Stack_Arr[i]<<" ";
//	}
//	cout<<endl;
//
//}
//
//void Pop()
//{
//	int num;
//	if(isEmpty == 0)
//		return;
//	cout<<"Pop : "<<endl;
//	for(int i = MAX_SIZE;i>0; i--)
//	{
//		cout<<Stack_Arr[top]<<" ";
//		num = Stack_Arr[top];
//		top = top -1;
//	}
//
//
//}
//int main()
//{
//	Push();
//	Display();
//	Pop();
//	Display();
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//#define m 3
//#define n 5
//void spiralPrint(int row, int col, int mat[m][n])
//{
//	int l =0,k=0;
//	while (k < row && l < col)
//    {
//		for(int i = 0;i<col;i++)
//		{
//			cout<<mat[k][i]<<" ";
//		}
//		k++;
//		for(int j = k;j<row;j++)
//		{
//			cout<<mat[j][n-1]<<" ";
//		}
//		col--;
//
//		if(k < row)
//		{
//			for (int i = col-1; i >= l; --i)
//            {
//                cout<<mat[row-1][i]<<" ";
//            }
//            row--;
//		}
//		 /*if (l < col)
//        {
//            for (int i = m-1; i >= k; --i)
//            {
//                printf("%d ", mat[i][l]);
//            }
//            l++;
//        }   */
//	}
//}
//
//
//int main()
//{
//	int mat[m][n] = {  {1,2,3,10,11},
//						{4,5,6,12,13},
//						{7,8,9,14,15}
//					};
//
//    spiralPrint(m, n, mat);
//    return 0;
//}

//print unique data from matrix
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int mat[4][4] = {
//					{1,0,1,1},
//					{0,0,1,0},
//					{1,0,1,1},
//					{1,1,1,0}
//					};
//
//	int l =0, m=1;
//	int cnt = 0;
//
//	while(l<4 && m<4)
//	{
//		int k = 0;
//		int n = 0;
//		while(k<4 && n<4)
//		{
//			if(mat[l][k] == mat[m][n])
//			{
//				cnt++;
//			}
//
//			k++;
//			n++;
//
//		}
//		if(4 != cnt)
//		{
//			for(int i =0;i<4;i++)
//			{
//				cout<<mat[m][i]<<" ";
//			}
//			cout<<endl;
//		}
//		cnt = 0;
//		l++;
//		m++;
//	}
//
//
//}
//
////find sum of array elements
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int arr[] = {15,5,10,10,3,4,5,5,6,13,7,3,17};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	int sum = 20;
//	int k;
//	int Total;
//
//	for(int i =0; i<n;i++)
//	{
//		k = 1;
//		k = k + i;
//		while(k<n)
//		{
//			Total = 0;
//			Total = arr[i] + arr[k];
//			if(sum == Total)
//			{
//				cout<<" Array element index "<<i <<" : "<<arr[i]<<" AND"<<" Array element index "<<k<<" : "<<arr[k]<<endl;
//			}
//			k++;
//		}
//	}
//
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//    int a = 10;
//    printf("\n %d %d", a, a++);
//    a = 10;
//    printf("\n %d %d", a++, a);
//    a = 10;
//    printf("\n %d %d %d ", a, a++, ++a);
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//template <class T>
//void fun(T a)
//{
//   cout << "The main template fun(): " << a << endl;
//}
//
//template<>
//void fun(int a)
//{
//    cout << "Specialized Template for int type: " << a << endl;
//}
//
//template<>
//void fun(char g)
//{
//	cout<<"Specialized Template for char : "<<g<<endl;
//}
//template<class R>
//void swap(R a, R b)
//{
//	R c;
//	c = a;
//	a = b;
//	b = c;
//	cout<<"A : "<<a<<endl;
//	cout<<"B : "<<b<<endl;
//
//
//}
//
//int main()
//{
//    /*fun<char>('a');
//    fun<int>(10);
//    fun<float>(10.14);*/
//
//	fun('a');
//    fun(10);
//    fun(10.14);
//	fun("ABC");
//	swap(10,20);
//	swap('A','B');
//}

//#include<iostream>
//
//using namespace std;
//
//template<class T>
//class Test
//{
//public:
//	Test()
//	{
//		cout<<"General template call."<<endl;
//	}
//
//};
//
//template<>
//class Test <int>
//{
//public:
//	Test()
//	{
//		cout<<"Specalized template call."<<endl;
//	}
//};
//
//int main()
//{
//	Test<int>a;
//	Test<char>b;
//	Test<float>c;
//	//Test<t>;
//
//	return 0;
//}

//#include <iostream>
//#include<memory>
//
//using namespace std;
//
//// A sample function f1() that throws an int exception
//void f1() throw (int) {
//  cout<<"\n f1() Start ";
//  throw 100;
//  cout<<"\n f1() End ";
//}
//
//// Another sample function f2() that calls f1()
//void f2() /*throw (int)*/ {
//  cout<<"\n f2() Start ";
//  try{
//  f1();
//  }
//  catch(int i) {
//   cout<<"\n Caught Exception: "<<i;
//  }
//  cout<<"\n f2() End ";
//}
//
//// Another sample function f3() that calls f2() and handles exception thrown by f1()
//void f3() {
//  cout<<"\n f3() Start ";
//  try {
//    f2();
//  }
//  catch(int i) {
//   cout<<"\n Caught Exception: "<<i;
//  }
//  cout<<"\n f3() End";
//}
//
//// A driver function to demonstrate Stack Unwinding  process
//int main() {
//
//
//  f3();
//  getchar();
//  return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//private:
//    static bool instanceFlag;
//    static Singleton *single;
//    Singleton()
//    {
//        //private constructor
//    }
//public:
//    static Singleton* getInstance();
//    void method();
//    ~Singleton()
//    {
//        instanceFlag = false;
//    }
//};
//
//bool Singleton::instanceFlag = false;
//Singleton* Singleton::single = NULL;
//Singleton* Singleton::getInstance()
//{
//    if(! instanceFlag)
//    {
//        single = new Singleton();
//        instanceFlag = true;
//        return single;
//    }
//    else
//    {
//        return single;
//    }
//}
//
//void Singleton::method()
//{
//    cout << "Method of the singleton class" << endl;
//}
//
//int main()
//{
//    Singleton *sc1,*sc2;
//    sc1 = Singleton::getInstance();
//    sc1->method();
//    sc2 = Singleton::getInstance();
//    sc2->method();
//
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//private:
//	Base()
//	{
//		cout<<"Singleton : Private Ctor"<<endl;
//	}
//public:
//	static Base *b;
//	static void *myFunction()
//	{
//		Base *b = new Base();
//		return b;
//
//	}
//	~Base()
//	{
//		cout<<"Singleton : Private Dtor"<<endl;
//		delete b;
//	}
//
//};
//Base* Base ::b = NULL;
//
//int main()
//{
//	Base::myFunction();
//	return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//private:
//    static bool instanceFlag;
//    static Singleton *single;
//    Singleton()
//    {
//        //private constructor
//		cout << "Ctor" << endl;
//    }
//public:
//    static Singleton* getInstance();
//    void method();
//    ~Singleton()
//    {
//		cout << "Dtor" << endl;
//        instanceFlag = false;
//    }
//};
//
//bool Singleton::instanceFlag = false;
//Singleton* Singleton::single = NULL;
//Singleton* Singleton::getInstance()
//{
//    if(! instanceFlag)
//    {
//        single = new Singleton();
//        instanceFlag = true;
//		delete single;
//        return single;
//    }
//    else
//    {
//        return single;
//    }
//}
//
//void Singleton::method()
//{
//    cout << "Method of the singleton class" << endl;
//}
//
//int main()
//{
//    Singleton *sc1,*sc2;
//    sc1 = Singleton::getInstance();
//    sc1->method();
//    sc2 = Singleton::getInstance();
//    sc2->method();
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Container {
//	int * m_Data;
//public:
//	Container() {
//		//Allocate an array of 20 int on heap
//		m_Data = new int[20];
//
//		std::cout << "Constructor: Allocation 20 int" << std::endl;
//	}
//	~Container() {
//		if (m_Data) {
//			delete[] m_Data;
//			m_Data = NULL;
//		}
//	}
//	//Copy Constructor
//	Container(const Container & obj) {
//		//Allocate an array of 20 int on heap
//		m_Data = new int[20];
//
//		//Copy the data from passed object
//		for (int i = 0; i < 20; i++)
//			m_Data[i] = obj.m_Data[i];
//
//		std::cout << "Copy Constructor: Allocation 20 int" << std::endl;
//	}
//
//	//Assignment Operator
//	Container & operator=(const Container & obj) {
//
//		if(this != &obj)
//		{
//			//Allocate an array of 20 int on heap
//			m_Data = new int[20];
//
//			//Copy the data from passed object
//			for (int i = 0; i < 20; i++)
//				m_Data[i] = obj.m_Data[i];
//
//			std::cout << "Assigment Operator: Allocation 20 int" << std::endl;
//		}
//	}
//
//	// Move Constructor
//	Container(Container && obj)
//	{
//		// Just copy the pointer
//		m_Data = obj.m_Data;
//
//		// Set the passed object's member to NULL
//		obj.m_Data = NULL;
//
//		std::cout<<"Move Constructor"<<std::endl;
//	}
//
//	// Move Assignment Operator
//	Container& operator=(Container && obj)
//	{
//		if(this != &obj)
//		{
//			// Just copy the pointer
//			m_Data = obj.m_Data;
//
//			// Set the passed object's member to NULL
//			obj.m_Data = NULL;
//
//			std::cout<<"Move Assignment Operator"<<std::endl;
//			return *this;
//		}
//	}
//
//};
//
//// Create am object of Container and return
//Container getContainer()
//{
//	Container obj;
//	return obj;
//}
//int main() {
//	// Create a vector of Container Type
//	std::vector<Container> vecOfContainers;
//
//	//Add object returned by function into the vector
//	vecOfContainers.push_back(getContainer());
//
//	Container obj;
//	obj = getContainer();
//
//	return 0;
//}

//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{}
//	virtual void Display() = 0;
//	virtual ~Base(){};
//
//};
//class Derived :  public Base
//{
//public:
//	Derived(){}
//	void Display()
//	{}
//	~Derived(){}
//
//};
//
//int main()
//{
//	shared_ptr<Base>b(new Derived());
//	b->Display();
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Display()
//	{
//		cout<<"Base : Display"<<endl;
//	}
//
//};
//
//class Derived: public Base
//{
//public:
//	void Display()
//	{
//		cout<<"Derived : Display"<<endl;
//	}
//	void Show()
//	{
//		cout<<"Derived : Show"<<endl;
//	}
//};
//
//int main()
//{
//	Base *bptr = new Derived();
//	//bptr->Display();
//	Derived *d = dynamic_cast<Derived *>(bptr);
//	d->Display();
//	d->Show();
//
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//struct Date {
//    int d, m, y;
//};
//
//int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//
//int DiffBetDates(Date dt1, Date dt2)
//{
//    int num1, num2;
//    int diff;
//
//    num1 = 365 * dt1.y + dt1.d;
//    num2 = 365 * dt2.y + dt2.d;
//
//    for (int i = 0; i < dt1.m - 1; i++)
//    {
//        num1 += month[i];
//        if (i == 1 && dt1.y % 4 == 0)
//        {
//            num1 += 1;
//        }
//
//    }
//    for (int i = 0; i < dt2.m - 1; i++)
//    {
//        num2 += month[i];
//        if (i == 1 && dt2.y % 4 == 0)
//        {
//            num2 += 1;
//        }
//    }
//
//    diff = num2 - num1;
//
//    return diff;
//
//}
//
//int main()
//{
//    int diff;
//    Date dt1 = { 1,2,2016 };
//    Date dt2 = { 1,3,2016 };
//    diff = DiffBetDates(dt1,dt2);
//    cout <<"Difference between two dates : " <<diff << " Days"<< endl;
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct node {
//    int data;
//    struct node *link;
//}*head =  NULL;
//
//void CreateLL()
//{
//    int num, n;
//    struct node *current, *tmp;
//    cout << "\n Enter no. of nodes : ";
//    cin >> n;
//    cout << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << "Enter data : ";
//        cin >> num;
//        cout << endl;
//        tmp = (struct node *) malloc(sizeof(struct node));
//        tmp->data = num;
//        tmp->link = NULL;
//        if (head == NULL)
//        {
//            head = tmp;
//            current = tmp;
//        }
//        else
//        {
//            while (current->link != NULL)
//            {
//                current = current->link;
//            }
//            current->link = tmp;
//            current = tmp;
//        }
//
//    }//end of for
//
//}
//
//
//void DisplayLL()
//{
//    if (head == NULL)
//        return;
//    struct node *ptr;
//    ptr = head;
//    while (ptr != NULL)
//    {
//        cout <<ptr->data <<"=>";
//        ptr = ptr->link;
//    }
//
//}
//
//void RemoveDupLL()
//{
//    if (head == NULL)
//        return;
//    struct node *ptr1, *ptr2, *dup;
//    ptr1 = head;
//    while (ptr1 != NULL && ptr1->link != NULL)
//    {
//        ptr2 = ptr1;
//        while (ptr2->link != NULL)
//        {
//            if (ptr1->data == ptr2->link->data)
//            {
//                dup = ptr2->link;
//                ptr2->link = ptr2->link->link;
//                free(dup);
//            }
//            else
//                ptr2 = ptr2->link;
//        }
//        ptr1 = ptr1->link;
//    }
//
//}
//
//void ReverseLL()
//{
//    struct node *ptr, *next, *prev;
//
//    if (head == NULL)
//        return;
//    ptr = head;
//    prev = NULL;
//
//    while (ptr != NULL)
//    {
//        next = ptr->link;
//        ptr->link = prev;
//        prev = ptr;
//        ptr = next;
//    }
//    head = prev;
//}
//
//int main()
//{
//    cout << "CreateLL : ";
//    CreateLL();
//    cout << endl;
//    cout << "DisplayLL : ";
//    DisplayLL();
//    cout << endl;
//    cout << "RemoveDupLL : ";
//    RemoveDupLL();
//    DisplayLL();
//    cout << endl;
//    cout << "ReverseLL : ";
//    ReverseLL();
//    DisplayLL();
//    cout << endl;
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int FindSecondLargest(int arr[], int n)
//{
//    int n1 = 0, n2 = 0,n3 = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] > n1)
//        {
//            n3 = n2;
//            n2 = n1;
//            n1 = arr[i];
//        }
//        else if (arr[i] > n2)
//        {
//            n3 = n2;
//            n2 = arr[i];
//        }
//        else if (arr[i] > n3)
//        {
//            n3 = arr[i];
//        }
//    }
//
//    cout << "First largest no. == " << n1 << endl;
//    cout << "Second largest no. == " <<n2 << endl;
//    cout << "Third largest no. == " << n3 << endl;
//
//    return n2;
//}
//
//int main()
//{
//    int arr[] = { 1,23,45,6,6,7,8,89,62,75,66,97,23,33,58,55,67 };
//    /*int sectors = 0;
//    int uVolInfoSize = 511;
//
//    sectors = uVolInfoSize;
//    while((sectors % 512) != 0) {
//        sectors++;
//    }
//    cout << "Sectors == " << sectors<< endl;*/
//    int n;
//    n = sizeof(arr) / sizeof(arr[0]);
//    FindSecondLargest(arr, n);
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct node {
//    int data;
//    struct node *left;
//    struct node *right;
//};
//
//struct node *newNode(int num)
//{
//    struct node *tmp;
//    tmp = (struct node *)malloc(sizeof(struct node));
//    tmp->data = num;
//    tmp->left = NULL;
//    tmp->right = NULL;
//
//    return tmp;
//}
//
//
//void PreOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    cout << ptr->data << " ";
//    PreOrder(ptr->left);
//    PreOrder(ptr->right);
//}
//
//void InOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    InOrder(ptr->left);
//    cout << ptr->data << " ";
//    InOrder(ptr->right);
//}
//
//void PostOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    PostOrder(ptr->left);
//    PostOrder(ptr->right);
//    cout << ptr->data<< " ";
//}
//
//void LevelTree(struct node *ptr, int level)
//{
//    if (ptr == NULL)
//        return;
//    if (level == 1)
//    {
//        cout <<ptr->data << " ";
//    }
//    else if (level > 1)
//    {
//        LevelTree(ptr->left, level - 1);
//        LevelTree(ptr->right, level - 1);
//    }
//
//}
//
//int HeightOfTree(struct node *ptr)
//{
//    if (ptr == NULL)
//        return 0;
//    int lHeight, rHeight;
//
//    lHeight = HeightOfTree(ptr->left);
//    rHeight = HeightOfTree(ptr->right);
//
//    if (lHeight > rHeight)
//        return lHeight + 1;
//    else
//        return rHeight + 1;
//}
//
//void LevelOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    int h;
//    h = HeightOfTree(ptr);
//    for (int i = 0; i < h; i++)
//    {
//        LevelTree(ptr,i);
//    }
//}
//
//void MirrorTree(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    struct node *tmp;
//    MirrorTree(ptr->left);
//    MirrorTree(ptr->right);
//
//    tmp = ptr->left;
//    ptr->left = ptr->right;
//    ptr->right = tmp;
//
//}
//
//void DoubleTree(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    struct node *tmp;
//
//    DoubleTree(ptr->left);
//    DoubleTree(ptr->right);
//
//    tmp = ptr->left;
//    ptr->left = newNode(ptr->data);
//    ptr->left->left = tmp;
//
//}
//
//int main()
//{
//    struct node *root;
//    root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->left->right->left = newNode(8);
//
//    cout << "PreOrder : ";
//    PreOrder(root);
//    cout << endl;
//    cout << "InOrder : ";
//    InOrder(root);
//    cout << endl;
//    cout << "PostOrder : ";
//    PostOrder(root);
//    cout << endl;
//    cout << "LevelOrder : ";
//    LevelOrder(root);
//    cout << endl;
//    cout << "MirrorTree : ";
//    MirrorTree(root);
//    LevelOrder(root);
//    cout << endl;
//    cout << "DoubleTree : ";
//    DoubleTree(root);
//    PostOrder(root);
//    cout << endl;
//
//    return 0;
//}


//#include<windows.h>
//
//
//typedef struct _VOLINFO
//{
//
//    WCHAR          PhysicalDeviceNameBuffer[512];
//    WCHAR          wcVolumeGuidBuffer[512];
//    ULONG VolumeType; //Normal or Snapshot
//    ULONG BitmapCount;
//    ULONGLONG VolumeSize;
//    ULONGLONG VolumeSize2;
//    ULONG  VolumeState;
//    ULONG failReasonCode;
//    ULONG VolSign;
//
//}VOLINFO, *PVOLINFO;
//
//typedef struct _MYBITMAPINFO
//{
//    ULONGLONG  TrackStartTime;
//    ULONGLONG  TrackStopTime;
//    ULONG      ChunkSize;
//    ULONG      ChunkSizeBitPower;
//    ULONG      BlockSize;
//    ULONG      BlockSizeBitPower;
//    ULONG      BitmapSize;
//    ULONG      BitmapState;
//    PUCHAR     ChunkTable[512];
//
//} MYBITMAPINFO, *PMYBITMAPINFO;
//
//void WriteStuctToFile(PVOLINFO pVolInfo)
//{
//    BOOLEAN bResult = FALSE;
//    HANDLE hFile;
//    DWORD cbWritten = 0, cbWritten1 = 0;
//    OVERLAPPED liByteOffset;
//    PMYBITMAPINFO pBitmapInfo = NULL;
//    ULONGLONG   ullNextOffset = 0;
//
//
//    liByteOffset.Offset = 0;
//
//    pVolInfo = (PVOLINFO)malloc(sizeof(VOLINFO));
//    memset(pVolInfo, 0, sizeof(VOLINFO));
//
//    pVolInfo->BitmapCount = 2;
//    wcscpy(pVolInfo->PhysicalDeviceNameBuffer, L"VolInfo");
//    pVolInfo->VolSign = 0xCCAA;
//    pVolInfo->VolumeSize = 1111;
//    pVolInfo->VolumeSize2 = 2222;
//    pVolInfo->VolumeState = 1;
//    pVolInfo->VolumeType = 0;
//    wcscpy(pVolInfo->wcVolumeGuidBuffer, L"VolInfo2");
//
//    hFile = CreateFile(
//        L"D:\\1.txt",
//        GENERIC_READ | GENERIC_WRITE,
//        FILE_SHARE_WRITE,
//        NULL,
//        OPEN_EXISTING,
//        FILE_ATTRIBUTE_NORMAL,
//        NULL
//    );
//    if (hFile == INVALID_HANDLE_VALUE)
//    {
//        wprintf(L"CreateFile Failed. %d ",::GetLastError());
//    }
//
//    bResult = WriteFile(
//        hFile,
//        pVolInfo,
//        sizeof(VOLINFO),
//        &cbWritten,
//        NULL//&liByteOffset
//    );
//    if (FALSE == bResult)
//    {
//        wprintf(L"Write File Failed. %d ", ::GetLastError());
//    }
//    ullNextOffset += sizeof(VOLINFO);
//    liByteOffset.Offset = ullNextOffset;
//
//    /*for (int i = 0; i < pVolInfo->BitmapCount; i++)
//    {*/
//        pBitmapInfo = (PMYBITMAPINFO)malloc(sizeof(MYBITMAPINFO));
//        memset(pBitmapInfo, 0, sizeof(MYBITMAPINFO));
//
//        pBitmapInfo->BitmapSize = 111;
//        pBitmapInfo->BitmapState = 1;
//        pBitmapInfo->BlockSize = 222;
//        pBitmapInfo->ChunkSize = 333;
//
//        bResult = WriteFile(
//                    hFile,
//                    pBitmapInfo,
//                    sizeof(MYBITMAPINFO),
//                    &cbWritten1,
//                   NULL//&liByteOffset
//                    );
//        if (FALSE == bResult)
//        {
//            wprintf(L"Write File Failed.");
//        }
//
//    //}
//
//    CloseHandle(hFile);
//
//
//}
//
//void ReadStuctToFile(PVOLINFO pVolInfo)
//{
//    BOOLEAN bResult = FALSE;
//    HANDLE hFile = INVALID_HANDLE_VALUE;
//    DWORD cbWritten = 0, cbRead = 0;
//    PMYBITMAPINFO pBitmapInfo = NULL;
//
//    pVolInfo = (PVOLINFO)malloc(sizeof(VOLINFO));
//    memset(pVolInfo, 0, sizeof(VOLINFO));
//
//    hFile = CreateFile(
//            L"D:\\1.txt",
//            GENERIC_READ | GENERIC_WRITE,
//            FILE_SHARE_READ,
//            NULL,
//            OPEN_EXISTING,
//            FILE_ATTRIBUTE_NORMAL,
//            NULL
//        );
//    if (hFile == INVALID_HANDLE_VALUE)
//    {
//        wprintf(L"CreateFile Failed.");
//    }
//
//    bResult = ReadFile(
//        hFile,
//        pVolInfo,
//        sizeof(VOLINFO),
//        &cbRead,
//        NULL
//    );
//    if (FALSE == bResult)
//    {
//        wprintf(L"ReadFile Failed.");
//
//    }
//
//    wprintf(L"Bitmap count == %d \n", pVolInfo->BitmapCount);
//    wprintf(L"PhysicalDeviceNameBuffer == %s \n", pVolInfo->PhysicalDeviceNameBuffer);
//    wprintf(L"Volsign == %x \n", pVolInfo->VolSign);
//    wprintf(L"Volume Size == %d \n", pVolInfo->VolumeSize);
//    wprintf(L"Volume Size2 == %d \n", pVolInfo->VolumeSize2);
//    wprintf(L"Volume State == %d \n", pVolInfo->VolumeState);
//    wprintf(L"Volume Type == %d \n", pVolInfo->VolumeType);
//    wprintf(L"VolumeGuidBuffer == %s \n", pVolInfo->wcVolumeGuidBuffer);
//
//    pBitmapInfo = (PMYBITMAPINFO)malloc(sizeof(MYBITMAPINFO));
//    memset(pBitmapInfo, 0, sizeof(MYBITMAPINFO));
//
//    bResult = ReadFile(
//        hFile,
//        pBitmapInfo,
//        sizeof(MYBITMAPINFO),
//        &cbRead,
//        NULL
//    );
//    if (FALSE == bResult)
//    {
//        wprintf(L"ReadFile Failed.");
//
//    }
//
//    CloseHandle(hFile);
//
//}
//
//int main()
//{
//
//    PVOLINFO pVolInfo = NULL;
//    PVOLINFO pVolInfo1 = NULL;
//
//    WriteStuctToFile(pVolInfo);
//    ReadStuctToFile(pVolInfo);
//
//    return 0;
//}


//#include <windows.h>
//
//int main()
//{
//
//
//    HKEY hKey;
//    LONG lResult;
//    DWORD dwType;
//    BOOLEAN bResult;
//    DWORD dwccbRegPath;
//    PBYTE szReglPath;
//
//    szReglPath = (PBYTE)malloc(4096);
//
//    bResult = FALSE;
//
//    //open registry key
//    lResult = RegOpenKeyEx(
//                    HKEY_LOCAL_MACHINE,
//                    L"SYSTEM\\MountedDevices",
//                    NULL,
//                    KEY_QUERY_VALUE | KEY_WOW64_64KEY,
//                    &hKey
//                    );
//
//    if (ERROR_SUCCESS != lResult)
//    {
//        printf("FATAL ERROR: Unable to output error code.\n");
//        free(szReglPath);
//        return bResult;
//    }
//
//    dwccbRegPath = sizeof(szReglPath) * 3;
//    //dwccbRegPath = 24;
//
//    //query for value in open registry key
//    lResult = RegQueryValueEx(
//                    hKey,
//                    L"\\DosDevices\\E:",
//                    NULL,
//                    &dwType,
//                    (LPBYTE)szReglPath,
//                    &dwccbRegPath
//                    );
//
//    if (ERROR_SUCCESS != lResult)
//    {
//        //close open regitsry key
//        RegCloseKey(
//            hKey
//        );
//        free(szReglPath);
//        return bResult;
//    }
//
//    //save first 4 bytes from regitsry to BYTE buffer
//    for (BYTE byCnt = 0; byCnt <dwccbRegPath; byCnt++)
//    {
//       printf("%x \t",szReglPath[byCnt]);
//    }
//    RegCloseKey(hKey);
//
//    bResult = TRUE;
//    return bResult;
//
//}


//#include<iostream>
//
//using namespace std;
//
//struct node {
//    int data;
//    struct node *left;
//    struct node *right;
//};
//
//struct node *newNode(int item)
//{
//    struct node *tmp;
//    tmp = (struct node *)malloc(sizeof(struct node));
//    tmp->data = item;
//    tmp->left = NULL;
//    tmp->right = NULL;
//    return tmp;
//
//}
//
//
//void PreOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    cout <<ptr->data <<" " ;
//    PreOrder(ptr->left);
//    PreOrder(ptr->right);
//}
//
//
//void InOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    InOrder(ptr->left);
//    cout << ptr->data << " ";
//    InOrder(ptr->right);
//}
//
//
//void PostOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    PostOrder(ptr->left);
//    PostOrder(ptr->right);
//    cout << ptr->data << " ";
//
//}
//
//void LevelTree(struct node *ptr, int level)
//{
//    if (ptr == NULL)
//        return;
//    if (level == 1)
//        cout <<ptr->data << " ";
//    else if (level > 1)
//    {
//        LevelTree(ptr->left, level - 1);
//        LevelTree(ptr->right, level - 1);
//    }
//}
//
//
//int HeightOfTree(struct node *ptr)
//{
//    if (ptr == NULL)
//        return 0;
//    int lHeight, rHeight;
//
//    lHeight = HeightOfTree(ptr->left);
//    rHeight = HeightOfTree(ptr->right);
//
//    if (lHeight > rHeight)
//        return lHeight + 1;
//    else
//        return rHeight + 1;
//
//}
//
//void LevelOrder(struct node *ptr)
//{
//    if (ptr == NULL)
//        return;
//    int h;
//    h = HeightOfTree(ptr);
//    for (int i = 0; i <= h; i++)
//        LevelTree(ptr,i);
//
//}
//
//int main()
//{
//    struct node *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->right->left->right = newNode(8);
//
//    cout << "PreOrder : ";
//    PreOrder(root);
//    cout << endl;
//    cout << "InOrder : ";
//    InOrder(root);
//    cout << endl;
//    cout << "PostOrder : ";
//    PostOrder(root);
//    cout << endl;
//    cout << "LevelOrder : ";
//    LevelOrder(root);
//    cout << endl;
//    cin.tie()
//
//
//    return 0;
//}


///**************************************************************************
//CreateDwordValueInCapabilityRegistry()
//
//IN Pdo: PhysicalDeviceObject
//IN categoryGUID: Category GUID eg KSCATEGORY_CAPTURE
//
//1. Get Symbolic name for interface
//2. Open registry key for storing information about a
//particular device interface instance
//3. Create Capabilities key under "Device Parameters" key
//4. Create a DWORD value "TestCapValueDWORD" under Capabilities
//
//Must be running at IRQL = PASSIVE_LEVEL in the context of a system thread
//**************************************************************************/
//NTSTATUS CreateDwordValueInCapabilityRegistry(IN PDEVICE_OBJECT pdo, IN GUID categoryGUID)
//
//{
//
//    // 1. Get Symbolic name for interface
//    // pSymbolicNameList can contain multiple strings if pdo is NULL.
//    // Driver should parse this list of string to get
//    // the one corresponding to current device interface instance.
//    PWSTR  pSymbolicNameList = NULL;
//
//    NTSTATUS ntStatus = IoGetDeviceInterfaces(
//        &categoryGUID,
//        pdo,
//        DEVICE_INTERFACE_INCLUDE_NONACTIVE,
//        &pSymbolicNameList);
//    if (NT_SUCCESS(ntStatus) && (NULL != pSymbolicNameList))
//    {
//        HANDLE hDeviceParametersKey = NULL;
//        UNICODE_STRING symbolicName;
//
//        // 2. Open registry key for storing information about a
//        // particular device interface instance
//        RtlInitUnicodeString(&symbolicName, pSymbolicNameList);
//        ntStatus = IoOpenDeviceInterfaceRegistryKey(
//            &symbolicName,
//            KEY_READ | KEY_WRITE,
//            &hDeviceParametersKey);
//        if (NT_SUCCESS(ntStatus))
//        {
//            OBJECT_ATTRIBUTES objAttribSubKey;
//            UNICODE_STRING subKey;
//
//            // 3. Create Capabilities key under "Device Parameters" key
//            RtlInitUnicodeString(&subKey, L"Capabilities");
//            InitializeObjectAttributes(&objAttribSubKey,
//                &subKey,
//                OBJ_KERNEL_HANDLE,
//                hDeviceParametersKey,
//                NULL);
//
//            HANDLE hCapabilityKeyHandle = NULL;
//
//            ntStatus = ZwCreateKey(&hCapabilityKeyHandle,
//                KEY_READ | KEY_WRITE | KEY_SET_VALUE,
//                &objAttribSubKey,
//                0,
//                NULL,
//                REG_OPTION_NON_VOLATILE,
//                NULL);
//            if (NT_SUCCESS(ntStatus))
//            {
//                OBJECT_ATTRIBUTES objAttribDwordKeyVal;
//                UNICODE_STRING subValDword;
//
//                // 4. Create a DWORD value "TestCapValueDWORD" under Capabilities
//                RtlInitUnicodeString(&subValDword, L"TestCapValueDWORD");
//
//                ULONG data = 0xaaaaaaaa;
//
//                ntStatus = ZwSetValueKey(hCapabilityKeyHandle, &subValDword, 0, REG_DWORD, &data, sizeof(ULONG));
//                ZwClose(hCapabilityKeyHandle);
//            }
//        }
//        ZwClose(hDeviceParametersKey);
//        ExFreePool(pSymbolicNameList);
//    }
//
//    return ntStatus;
//}


//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//    virtual void Show()
//    {
//        cout << "Base : Show "<< endl;
//    }
//
//    void Display()
//    {
//        cout << "Base : Display"<< endl;
//    }
//
//};
//
//class Derived : public Base
//{
//public:
//    void Show()
//    {
//        cout << "Derived : Show"<< endl;
//    }
//
//    void Display()
//    {
//        cout << "Derived : Display"<< endl;
//    }
//    void Print()
//    {
//        cout << "Derived : Print"<< endl;
//    }
//};
//
//
//int main()
//{
//    Base *bPtr = new Derived();
//    //bPtr->Display();
//    //bPtr->Show();
//
//    Derived *d = dynamic_cast<Derived *>(bPtr);
//    d->Display();
//    d->Print();
//    d->Show();
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    long buff = 0x7fffffff;
//
//    try{
//        char *ptr = new char[buff];
//        cout << "Memory Allocation Success."<< endl;
//    }
//    catch (bad_alloc &e)
//    {
//        cout <<"Insufficient Memory. " <<e.what() << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//    int len;
//    char *name;
//public:
//    Base()
//    {
//        len = 0;
//        name = 0;
//        cout << "Default Constructor." << endl;
//    }
//    Base(char *tmp)
//    {
//        len = strlen(tmp);
//        name = new char[len];
//        strcpy(name,tmp);
//        cout << "Parametrized Constructor : " << name << endl;
//    }
//    Base(const Base &b)
//    {
//        len = strlen(b.name);
//        name = new char[len];
//        strcpy(name,b.name);
//        cout << "Copy Constructor : "<< name << endl;
//    }
//    Base& operator=(const Base &b)
//    {
//        //if (this != &b)
//        {
//            len = strlen(b.name);
//            name = new char[len];
//            strcpy(name,b.name);
//            cout << "Assignment Opeartor : "<< name<< endl;
//            return *this;
//
//        }
//    }
//
//    friend Base operator+(const Base &b1, const Base &b2);
//
//};
//
//Base operator+(const Base &b1, const Base &b2)
//{
//    Base tmp;
//
//    tmp.len = strlen(b1.name) + strlen(b2.name);
//    tmp.name = new char[tmp.len];
//    strcpy(tmp.name,b1.name);
//    strcat(tmp.name,b2.name);
//    cout << "+ operator : "<< tmp.name<< endl;
//    return tmp.name;
//}
//
//int main()
//{
//    char *str1 = "Rohit";
//    char *str2 = "Khajindar";
//
//    Base b1;
//    Base b2(str1);
//    Base b3(str2);
//   /* Base b4(b2);
//    Base b5 = b3;
//    Base b6;
//    b6 = b4;
//    Base b7;
//    b7 = b5;*/
//    Base b9;
//    b9 = b9;
//
//   /* Base b8 = b4 = b5;
//    cout << "+ operator" << endl;
//    b6 + b7;*/
//
//
//    return 0;
//}

//#include <windows.h>
//
//using namespace std;
//
//int main{
//
//    int *arr1;
//    int *arr2;
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//
//    int *arr1[10] = { 0 };
//    int *arr2[10] = { 0 };
//    int size1 = 0;
//    int size2 = 0;
//    int j = 0;
//    int counter = 0;
//    int chunkSz1 = 1024;
//    int ChunkSz2 = 8192;
//    int offset = 0;
//    bool isNULL = true;
//
//
//    for (int i = 0; i < 10;)
//    {
//        arr2[i] = (int *)malloc(chunkSz1);
//        memset(arr2[i], '&', sizeof(arr2[i]));
//        i += 1;
//    }
//
//    //
//    //Chunk Size Calc
//    //
//    size1 = ChunkSz2/chunkSz1 ;
//
//    for (int i = 0; i < 10;)
//    {
//        //size1 = sizeof(arr2[i]) / ChunkSz2;
//        counter = 0;
//        do
//        {
//            if (arr2[j])
//            {
//                if (!arr1[i])
//                {
//                    arr1[i] = (int *)malloc(ChunkSz2);
//                }
//
//                for (int l = 0; l < chunkSz1 / sizeof(int); l++, offset++)
//                {
//                    cout << "j l i off" << j << " " << l << " " << i << " " << offset << endl;
//                    arr1[i][offset] += arr2[j][l];
//                }
//
//                isNULL = false;
//            }
//            else
//            {
//                //arr1[i] = NULL;
//                offset += chunkSz1 / sizeof(int);
//            }
//
//            j++;
//            if (j >= 10)
//                break;
//            counter++;
//        } while (counter < size1);
//
//        if (isNULL)
//            arr1[i] = NULL;
//        else
//            isNULL = true;
//
//        if (j >= 10)
//            break;
//
//        i++;
//        offset = 0;
//    }
//
//
//
//    //int *arr1[10] = {0};
//    //int *arr2[10] = {0};
//    //int size1 = 0;
//    //int size2 = 0;
//    //int j = 0;
//    //int counter = 0;
//    //int chunkSz1 = 8192;
//    //int ChunkSz2 = 1024;
//    //int offset = 0;
//
//
//    //for (int i = 1; i < 10;)
//    //{
//    //    arr2[i] = (int *)malloc(chunkSz1);
//    //    memset(arr2[i], '&', sizeof(arr2[i]));
//    //    i += 2;
//    //}
//
//    ////
//    ////Chunk Size Calc
//    ////
//    //size1 = chunkSz1 / ChunkSz2;
//
//    //for (int i = 0; i < 10;)
//    //{
//    //    //size1 = sizeof(arr2[i]) / ChunkSz2;
//    //    counter = 0;
//    //    do
//    //       {
//    //        if (arr2[i])
//    //        {
//    //            if (!arr1[j])
//    //            {
//    //                arr1[j] = (int *)malloc(ChunkSz2);
//    //            }
//    //
//    //            for (int l = 0; l < ChunkSz2/sizeof(int); l++, offset++)
//    //            {
//    //                if (l == 512)
//    //                {
//    //                    cout << "Hi" << endl;
//    //                }
//    //                cout << "j l i off" << j << " " << l << " " << i << " " << offset << endl;
//    //                arr1[j][l] += arr2[i][offset];
//    //            }
//    //        }
//    //        else
//    //        {
//    //            arr1[j] = NULL;
//    //        }
//
//    //        j++;
//    //        if (j >= 10)
//    //            break;
//    //        counter++;
//    //    } while (counter < size1);
//
//    //    if (j >= 10)
//    //        break;
//
//    //    i++;
//    //    offset = 0;
//    //}
//
//    return 0;
//}

//#include<Windows.h>
//
//#define CSCBT_REG_PATH    L"SYSTEM\\CurrentControlSet\\Services\\CSCBT"
//#define CSCBT_KEY_NAME    L"InstallDir"
//
//
//BOOLEAN
//GetCSCBTInstallPath(
//    WCHAR *pwszCSCBTRegPath,
//    DWORD dwcchCSCBTRegPath
//)
//
//{
//    HKEY hKey;
//    LONG lResult;
//    DWORD dwType;
//
//    if (NULL == pwszCSCBTRegPath)
//    {
//        wprintf(L"pwszCSCBTRegPath is NULL.");
//        return FALSE;
//    }
//
//    lResult = RegOpenKeyEx(
//                HKEY_LOCAL_MACHINE,
//                CSCBT_REG_PATH,
//                NULL,
//                KEY_QUERY_VALUE | KEY_WOW64_64KEY,
//                &hKey
//                );
//
//    if (ERROR_SUCCESS != lResult)
//    {
//        wprintf(L"RegOpenKeyEx Failed.");
//
//        return FALSE;
//    }
//
//   // dwcchCSCBTRegPath = sizeof(pwszCSCBTRegPath);
//
//    lResult = RegQueryValueExW(
//                hKey,
//                CSCBT_KEY_NAME,
//                NULL,
//                &dwType,
//                (LPBYTE)pwszCSCBTRegPath,
//                &dwcchCSCBTRegPath
//                );
//
//    if (ERROR_SUCCESS != lResult)
//    {
//        wprintf(L"RegQueryValueExW Failed.");
//
//        RegCloseKey(
//            hKey
//        );
//
//        return FALSE;
//    }
//
//    RegCloseKey(hKey);
//
//    return TRUE;
//}
//
//int main()
//{
//
//
//    DWORD dwcchszCSCBTRegPath = MAX_PATH;
//    TCHAR tszszCSCBTRegPath[MAX_PATH] = { 0 };
//    BOOLEAN  bReturn = FALSE;
//
//    bReturn = GetCSCBTInstallPath(
//                tszszCSCBTRegPath,
//                dwcchszCSCBTRegPath
//                );
//
//    if (FALSE == bReturn)
//    {
//        wprintf(L"GetCSCBTInstallPath Failed.");
//    }
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct Date { int d, m, y; };
//
//int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//
//int DiiferenceBetDates(Date dt1, Date dt2)
//{
//    int diff;
//    int num1;
//    int num2;
//
//    num1 = 365 * dt1.y  * dt1.d;
//    num2 = 365 * dt2.y * dt2.d;
//
//    for (int i = 0;i < dt1.m - 1; i++)
//    {
//        num1 += month[i];
//        if (i == 1 && dt1.y % 4 == 0)
//        {
//            num1 += 1;
//        }
//    }
//
//    for (int i = 0; i < dt2.m - 1; i++)
//    {
//        num2 += month[i];
//        if ( i == 1 && dt2.y % 4 == 0)
//        {
//            num2 += 1;
//        }
//    }
//
//    diff = num2 - num1;
//    return diff;
//
//}
//
//int main()
//{
//    int diff;
//    Date dt1 = { 1,3,2016 };
//    Date dt2 = { 1,4,2016 };
//
//    diff = DiiferenceBetDates(dt1,dt2);
//    cout <<"Difference between two dates : " <<diff <<" Days"<< endl;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct node {
//    int data;
//    struct node *link;
//}*head = NULL;
//
//
//void  CreateLL()
//{
//    int n, item;
//    struct node *tmp, *current;
//    cout << "Enter no. of nodes : ";
//    cin >> n;
//    cout << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << "Enter data : ";
//        cin >> item;
//        tmp = (struct node*) malloc(sizeof(struct node));
//        tmp->data = item;
//        tmp->link = NULL;
//        if (head == NULL)
//        {
//            head = tmp;
//            current = tmp;
//        }
//        else
//        {
//            while (current->link != NULL)
//            {
//                current = current->link;
//            }
//            current->link = tmp;
//            current = tmp;
//        }
//
//    }
//
//
//}
//
//void DisplayLL()
//{
//    struct node *ptr;
//    if (head == NULL)
//        return;
//    ptr = head;
//    while (ptr != NULL)
//    {
//        cout << ptr->data << "=>";
//        ptr = ptr->link;
//    }
//}
//
//void ReverseLL()
//{
//    struct node *ptr, *next, *prev;
//    if (head == NULL)
//        return;
//    ptr = head;
//    prev = NULL;
//    while (ptr != NULL)
//    {
//        next = ptr->link;
//        ptr->link = prev;
//        prev = ptr;
//        ptr = next;
//    }
//    head = prev;
//
//}
//
//void DeleteHeadLL()
//{
//    struct node *ptr;
//    if (head == NULL)
//        return;
//    ptr = head;
//    head = head->link;
//    free(ptr);
//
//}
//
//void DeleteEndLL()
//{
//    struct node *ptr;
//    if (head == NULL)
//        return;
//    ptr = head;
//    while (ptr->link->link != NULL)
//        ptr = ptr->link;
//    ptr->link = NULL;
//
//}
//
//void DeleteInBetLL(int num1, int num2)
//{
//    struct node *ptr1, *ptr2;
//    if (head == NULL)
//        return;
//    ptr1 = head;
//
//    while (ptr1->link != NULL)
//    {
//        ptr2 = ptr1->link;
//        if (ptr1->data == num1 && ptr2->link->data == num2)
//        {
//            ptr1->link = ptr2->link->link;
//            free(ptr2);
//        }
//        ptr1 = ptr1->link;
//    }
//
//}
//
//
//void RemoveDupLL()
//{
//    struct node *ptr1, *ptr2, *dup;
//
//    if (head == NULL)
//        return;
//    ptr1 = head;
//    while (ptr1 != NULL && ptr1->link != NULL)
//    {
//        ptr2 = ptr1;
//        while (ptr2->link != NULL)
//        {
//            if (ptr1->data == ptr2->link->data)
//            {
//                dup = ptr2->link;
//                ptr2->link = ptr2->link->link;
//                free(dup);
//            }
//            else
//                ptr2 = ptr2->link;
//        }
//        ptr1 = ptr1->link;
//    }
//
//}
//
//int main()
//{
//
//    cout << "CreateLL : ";
//    CreateLL();
//    cout << endl;
//
//    cout << "DisplayLL : ";
//    DisplayLL();
//    cout << endl;
//
//    cout << "DeleteHeadLL : ";
//    DeleteHeadLL();
//    DisplayLL();
//    cout << endl;
//
//    cout << "DeleteEndLL : ";
//    DeleteEndLL();
//    DisplayLL();
//    cout << endl;
//
//    cout << "DeleteInBetLL : ";
//    DeleteInBetLL(2,4);
//    DisplayLL();
//    cout << endl;
//
//    cout << "RemoveDupLL : ";
//    RemoveDupLL();
//    DisplayLL();
//    cout << endl;
//
//    cout << "ReverseLL : ";
//    ReverseLL();
//    DisplayLL();
//    cout << endl;
//
//    return 0;
//}


//#include <windows.h>
//#include <stdio.h>
//
//typedef struct __HARD_DISK_FOOTER
//{
//
//    ULONGLONG  ullCookie;
//    ULONG      ulFeatures;
//    ULONG      ulFileFormatVersion;
//    ULONGLONG  ullDataOffset;
//    ULONG      ulTimeStamp;
//    ULONG      ulCreatorApplication;
//    ULONG      ulCreatorVersion;
//    ULONG      ulCreatorHostOS;
//    ULONGLONG  ullOriginalSize;
//    ULONGLONG  ullCurrentSize;
//    USHORT     usDiskGeometryCylinder;
//    UCHAR      ucDiskGeometryHeads;
//    UCHAR      ucDiskGeometrySectors;
//    ULONG      ulDiskType;
//    ULONG      ulChecksum;
//    UCHAR      ucUniqueId[16];
//    UCHAR      ucSavedState;
//    ULONG      ulReserved;
//
//} HARD_DISK_FOOTER, *PHARD_DISK_FOOTER;
//
//typedef struct __HARD_DISK_HEADER
//{
//
//    ULONGLONG    ullCookie;
//    ULONGLONG    ullDataOffset;
//    ULONGLONG    ulTableOffset;
//    ULONG        ulHeaderVersion;
//    ULONG        ulMaxTableEntries;
//    ULONG        ulBlockSize;
//    ULONG        ulChecksum;
//    UCHAR        ucUniqueId[16];
//    ULONG        ulParentTimeStamp;
//    ULONG        ulReserved;
//    WCHAR        wzParentUnicodeName[512];
//    PVOID        ParentLocatorEntry;
//    ULONG        Reserved;
//
//} HARD_DISK_HEADER, *PHARD_DISK_HEADER;
//
//int main()
//{
//    HARD_DISK_FOOTER HardDiskFooterBigEndian;
//    HARD_DISK_HEADER HardDiskHeaderBigEndian;
//
//    int iFootersize = sizeof(HardDiskFooterBigEndian);
//    int iHeadersize = sizeof(HardDiskFooterBigEndian);
//
//
//    printf("Footer size == %d ", iFootersize);
//    printf("Header size == %d ", iHeadersize);
//
//
//    return 0;
//}



//#include "stdafx.h"
//#include <stddef.h>
//#include <stdio.h>
//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <strsafe.h>
//#include <Windows.h>
//
////macro for DBGPrint
//#undef CbtPrint
//#define CbtPrint OutputDebugString
//#define dbgprint(str) OutputDebugString(str);
//
//#define VOL_CBT_SUCCESS 1
//#define MODULE_CBTDLL _T("CSCBTDLL")
//#define PREFIX_CBTDLL MODULE_CBTDLL _T(" : ")
//#define TSTR(name) _T(#name)
//#define TO_TSTR(name) TSTR(name)
////Symbolic Link Name for Volume Filter driver
//#define NULL_CHAR '\0'
//#define lg printf(">>%d \n", __LINE__);
//#define BUFFERSIZE (10 * 1024 * 1024)
//#define CBT_ERROR 1
//#define CBT_SUCCESS 0
//
//#define DISK_MIRROR_FOOTER 512
//#define DISK_HEADER 1024
//#define DISK_2MB_ALLGIN (2*1024*1024)
//#define DISK_4K_ALLIGN 4096
//#define DISK_FOOTER 512
//
//
//
//
//
//ULONG gretval = 0;
//
//#define FIXED_HARD_DISK        2
//#define DYNAMIC_HARD_DISK      3
//#define DIFFERENCING_HARD_DISK 4
//
//
//#pragma pack(1)
//typedef struct __HARD_DISK_FOOTER
//{
//
//    ULONGLONG  ullCookie;
//    ULONG      ulFeatures;
//    ULONG      ulFileFormatVersion;
//    ULONGLONG  ullDataOffset;
//    ULONG      ulTimeStamp;
//    ULONG      ulCreatorApplication;
//    ULONG      ulCreatorVersion;
//    ULONG      ulCreatorHostOS;
//    ULONGLONG  ullOriginalSize;
//    ULONGLONG  ullCurrentSize;
//    USHORT     usDiskGeometryCylinder;
//    UCHAR      ucDiskGeometryHeads;
//    UCHAR      ucDiskGeometrySectors;
//    ULONG      ulDiskType;
//    ULONG      ulChecksum;
//    UCHAR      ucUniqueId[16];
//    UCHAR      ucSavedState;
//    ULONG      ulReserved;
//
//} HARD_DISK_FOOTER, *PHARD_DISK_FOOTER;
//
//
//
//#pragma pack(1)
//typedef struct __DYNAMIC_DISK_HEADER
//{
//    ULONGLONG ullCookie;
//    ULONGLONG ullDataOffset;
//    ULONGLONG ullTableOffset;
//    ULONG ulHeaderVersion;
//    ULONG ulMaxTableEntries;
//    ULONG ulBlockSize;
//    ULONG ulChecksum;
//    UCHAR ucParentUniqueID[16];
//    ULONG ulParentTimeStamp;
//    ULONG ulReserved;
//    UCHAR uncParentUnicodeName[512];
//    UCHAR ucParentLocatorEntry1[24];
//    UCHAR ucParentLocatorEntry2[24];
//    UCHAR ucParentLocatorEntry3[24];
//    UCHAR ucParentLocatorEntry4[24];
//    UCHAR ucParentLocatorEntry5[24];
//    UCHAR ucParentLocatorEntry6[24];
//    UCHAR ucParentLocatorEntry7[24];
//    UCHAR ucParentLocatorEntry8[24];
//    UCHAR ucReserved[256];
//} DYNAMIC_DISK_HEADER, *PDYNAMIC_DISK_HEADER;
//
//#pragma pack(1)
//typedef struct __CHS
//{
//    BYTE cylinder;
//    BYTE head;
//    BYTE sector;
//
//} CHS, *PCHS;
//
//#pragma pack(1)
//typedef struct __DISK_MBR
//{
//    BYTE chCode[440];
//    ULONG ulDiskSignature;
//    USHORT usUnused;
//
//    struct __DISK_MBR_PARTITION {
//
//        BYTE  chStatus;
//        CHS   firstAbsoluteSector;
//        BYTE  chPartitionType;
//        CHS   lastAbsoluteSector;
//        ULONG ulfirstAbsoluteSectorLba;
//        ULONG ulNoOfSectors;
//
//    } MbrPartition[4];
//
//    ULONG ulMbrSignature;
//
//} DISK_MBR, *PDISK_MBR;
//
//
//#define VHD_SECTOR_SIZE 512
//
//#define MBR_SIGNATURE         0xAA55
//#define MBR_STATUS_BOOTABLE   0x80
//
//#define CBT_ERROR -1;
//
//VOID CloseVolumeHandle();
//HANDLE OpenDestinationVolume(TCHAR *VolumeGuidPath);
//HANDLE OpenSourceVolume(TCHAR *VolumeGuidPath);
//void DisplayError(LPTSTR lpszFunction, DWORD dwErrorCode);
//int CopyFileVolBitmapToVolume(TCHAR *src_vol, TCHAR *dest_vol, PUCHAR src_volbitmapbuffer, ULONG src_volbitmap_size);
//ULONG cscbtGetFileBitmap(TCHAR *filepath, PUCHAR *pFileBitmap);
//ULONG cscbtGetVHDHeaders(TCHAR *vhdfilepath);
//ULONG cscbtGetVolumeBitmap(char *vhdfilepath, ULONG ulPartitionOffset, ULONG ulBitmapHandle, PUCHAR *pVolBitmap, PUCHAR fileBitmap, ULONG ulDiskType);
//BOOL cscbtSetVolumeOffset(HANDLE hVolume, ULONGLONG ullOffset);
//BOOL cscbtSetFileOffset(HANDLE hHandle, ULONGLONG ullOffset, ULONG startFrom);
//BOOL cscbtWriteData(HANDLE hDstVolume, CHAR *DataBuffer, DWORD dwBytesToWrite);
//BOOL cscbtReadData(HANDLE hSrcVolume, CHAR *DataBuffer, DWORD dwBytesToRead, DWORD *dwBytesRead);
//
//HARD_DISK_FOOTER    gHardDiskFooter;
//DYNAMIC_DISK_HEADER gDynamicDiskHeader;
//DISK_MBR            gDiskMbr;
//
//BOOL cscbtWriteData(HANDLE hDstVolume, CHAR *DataBuffer, DWORD dwBytesToWrite)
//{
//    DWORD dwBytesWritten = 0;
//    BOOL bErrorFlag = FALSE;
//
//    //_tprintf(TEXT("Writing %d bytes\n"), dwBytesToWrite);
//
//    bErrorFlag = WriteFile(
//        hDstVolume,           // open file handle
//        DataBuffer,      // start of data to write
//        dwBytesToWrite,  // number of bytes to write
//        &dwBytesWritten, // number of bytes that were written
//        NULL);            // no overlapped structure
//
//    if (FALSE == bErrorFlag)
//    {
//        gretval = CBT_ERROR;
//        DisplayError(TEXT("cscbtWriteData"), GetLastError());
//        printf("Terminal failure: Unable to write to file.\n");
//        return FALSE;
//    }
//    else
//    {
//        if (dwBytesWritten != dwBytesToWrite)
//        {
//            // This is an error because a synchronous write that results in
//            // success (WriteFile returns TRUE) should write all data as
//            // requested. This would not necessarily be the case for
//            // asynchronous writes.
//            gretval = CBT_ERROR;
//            printf("Error: dwBytesWritten != dwBytesToWrite\n");
//            return FALSE;
//        }
//        else
//        {
//            //_tprintf(TEXT("Wrote %d bytes successfully.\n"), dwBytesWritten);
//            return TRUE;
//        }
//    }
//
//}
//
//BOOL cscbtReadData(HANDLE hSrcVolume, CHAR *DataBuffer, DWORD dwBytesToRead, DWORD *dwBytesRead)
//{
//
//    BOOL bErrorFlag = FALSE;
//
//    // _tprintf(TEXT("Reading %d bytes\n"), dwBytesToRead);
//
//    bErrorFlag = ReadFile(
//        hSrcVolume,           // open file handle
//        DataBuffer,      // start of data to write
//        dwBytesToRead,  // number of bytes to write
//        dwBytesRead, // number of bytes that were written
//        NULL);            // no overlapped structure
//
//    if (FALSE == bErrorFlag)
//    {
//        gretval = CBT_ERROR;
//        DisplayError(TEXT("cscbtReadData"), GetLastError());
//        printf("Terminal failure: Unable to read from file.\n");
//        return FALSE;
//    }
//    else
//    {
//        if (*dwBytesRead <= 0)
//        {
//            gretval = CBT_ERROR;
//            // This is an error because a synchronous write that results in
//            // success (ReadFile returns TRUE) should read all data as
//            // requested. This would not necessarily be the case for
//            // asynchronous read.
//            //printf("\nRead Finished\n");
//            return TRUE;
//        }
//        else
//        {
//            // _tprintf(TEXT("Read %d bytes successfully.\n"), *dwBytesRead);
//            return TRUE;
//        }
//    }
//
//}
//
//BOOL cscbtSetVolumeOffset(HANDLE hVolume, ULONGLONG ullOffset)
//{
//
//    LARGE_INTEGER liOffset = { 0 };
//    liOffset.QuadPart = ullOffset;
//    DWORD dwOffsetPtr;
//
//    //Setting Destination Volume Offset
//    dwOffsetPtr = SetFilePointer(hVolume,
//        liOffset.LowPart,
//        &liOffset.HighPart,
//        FILE_BEGIN);
//
//    if (dwOffsetPtr == INVALID_SET_FILE_POINTER || -1 == dwOffsetPtr)
//    {
//        printf(" Destination File : cscbtSetFileOffset Error = \n");
//        DisplayError(L"cscbtSetFileOffset", GetLastError());
//        gretval = CBT_ERROR;
//        return FALSE;
//    }
//
//    return TRUE;
//
//}
//HANDLE OpenSourceVolume(TCHAR *VolumeGuidPath)
//{
//    HANDLE hSrcVolume = CreateFile(VolumeGuidPath,            // name of the write
//        GENERIC_READ,
//        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
//        NULL,
//        OPEN_EXISTING,
//        FILE_ATTRIBUTE_REPARSE_POINT,
//        NULL);
//
//    if (hSrcVolume == INVALID_HANDLE_VALUE)
//    {
//        DisplayError(TEXT("OpenSourceVolume"), GetLastError());
//        _tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for read.\n"), VolumeGuidPath);
//        gretval = CBT_ERROR;
//        return hSrcVolume;
//    }
//
//    return hSrcVolume;
//
//}
//
//HANDLE OpenDestinationVolume(TCHAR *VolumeGuidPath)
//{
//    DWORD status;
//    HANDLE hDstVolume = CreateFile(VolumeGuidPath,            // name of the write
//        GENERIC_READ | GENERIC_WRITE,
//        FILE_SHARE_READ | FILE_SHARE_WRITE,
//        NULL,
//        OPEN_EXISTING,
//        FILE_ATTRIBUTE_NORMAL,
//        NULL);
//
//    if (hDstVolume == INVALID_HANDLE_VALUE)
//    {
//        DisplayError(TEXT("OpenDestinationVolume"), GetLastError());
//        _tprintf(TEXT("Terminal failure: Unable to open volume \"%s\" for write.\n"), VolumeGuidPath);
//        gretval = CBT_ERROR;
//        return INVALID_HANDLE_VALUE;
//    }
//
//    if (!DeviceIoControl(hDstVolume,
//        FSCTL_LOCK_VOLUME,
//        NULL,
//        0,
//        NULL,
//        0,
//        &status,
//        NULL))
//    {
//        gretval = CBT_ERROR;
//        DisplayError(TEXT("OpenDestinationVolume"), GetLastError());
//        CloseHandle(hDstVolume);
//        hDstVolume = INVALID_HANDLE_VALUE;
//    }
//
//    return hDstVolume;
//
//}
//
//
//ULONGLONG fileSectorAddr = 0;
//ULONGLONG diskSectorAddr = 0;
//HARD_DISK_FOOTER HardDiskFooterBigEndian;
//HARD_DISK_FOOTER HardDiskFooter;
//PULONG gBAT = NULL;
//PULONG BATbig = NULL;
//DYNAMIC_DISK_HEADER DynamicDiskHeaderBigEndian;
//DYNAMIC_DISK_HEADER DynamicDiskHeader;
//UCHAR blockBitmap[512];
//CHAR sectorBuffer[4096];
//UCHAR sectorBits = 0;
//UCHAR shiftMask = 0;
//FILE *fd;
//DISK_MBR diskMbr;
//ULONG bitmapAddr = 0;
//ULONG mbrAddr = 0;
//ULONG volAddr = 0;
//ULONG volSize = 0;
//bool bClone = true;
//ULONG start_bmp_byte = 0;
//ULONG start_bmp_bit = 0;
//ULONG bmp_byte = 0;
//ULONG bmp_bit = 0;
//PUCHAR bmp_buffer = NULL;
//UCHAR databyte = 0;
//ULONG trackAddr = NULL;
//ULONG bits_to_read = 0;
//
//int sectorIndex = 0;
//int volAbsoluteStartSector = 0;
//int volAbsoluteEndSector = 0;
//bool volStartSectorFound = false;
//
//ULONG partial_sector_count = 0;
//
//PUCHAR volBitmap = NULL;
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//
//    PUCHAR fileBitmap = NULL;
//    ULONG fileBitmapSizeInBytes = 0;
//
//    PUCHAR volBitmap = NULL;
//    ULONG volBitmapSizeInBytes = 0;
//    ULONG ulDiskType;
//
////#define VHD_FILE_PATH_W L"C:\\1.vhd"
////#define VHD_FILE_PATH_W L"C:\\100MB.vhd"
//
////#define VHD_FILE_PATH_W L"C:\\2.vhd"
//
//#define VHD_FILE_PATH_W L"C:\\500GB.vhd"
//#define VHD_FILE_PATH    "C:\\f1.vhd"
//
//    // Read VHD Headers
//    ulDiskType = cscbtGetVHDHeaders(VHD_FILE_PATH_W);
//
//    // Get Bitmap of VHD file
//    fileBitmapSizeInBytes = cscbtGetFileBitmap(VHD_FILE_PATH_W, &fileBitmap);
//
//    // Get Volume Bitmap of a disk partition from VHD file bitmap
//    volBitmapSizeInBytes = cscbtGetVolumeBitmap(VHD_FILE_PATH, 0, 0, &volBitmap, fileBitmap, ulDiskType);
//
//    if (volBitmapSizeInBytes) {
//        //where F: is NTFS and J: is RAW
//        CopyFileVolBitmapToVolume(L"\\\\.\\K:", L"\\\\.\\J:", volBitmap, volBitmapSizeInBytes);
//    }
//
//    //fclose(fd);
//
//}
//
//
//void DisplayError(LPTSTR lpszFunction, DWORD dwErrorCode)
//// Routine Description:
//// Retrieve and output the system error message for the last-error code
//{
//    LPVOID lpMsgBuf;
//    LPVOID lpDisplayBuf;
//    DWORD dw = dwErrorCode;
//
//    FormatMessage(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER |
//        FORMAT_MESSAGE_FROM_SYSTEM |
//        FORMAT_MESSAGE_IGNORE_INSERTS,
//        NULL,
//        dw,
//        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//        (LPTSTR)&lpMsgBuf,
//        0,
//        NULL);
//
//    lpDisplayBuf =
//        (LPVOID)LocalAlloc(LMEM_ZEROINIT,
//        (lstrlen((LPCTSTR)lpMsgBuf)
//            + lstrlen((LPCTSTR)lpszFunction)
//            + 40) // account for format string
//            * sizeof(TCHAR));
//
//    if (FAILED(StringCchPrintf((LPTSTR)lpDisplayBuf,
//
//        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//        TEXT("%s failed with error code %d as follows:\n%s"),
//        lpszFunction,
//        dw,
//        lpMsgBuf)))
//    {
//        printf("FATAL ERROR: Unable to output error code.\n");
//    }
//
//    _tprintf(TEXT("ERROR: %s\n"), (LPCTSTR)lpDisplayBuf);
//
//    LocalFree(lpMsgBuf);
//    LocalFree(lpDisplayBuf);
//}
//
//
//int CopyFileVolBitmapToVolume(TCHAR *src_vol_path, TCHAR *dest_vol_path, PUCHAR src_volbitmapbuffer, ULONG src_volbitmap_size)
//{
//    DWORD  dwBytesToRead = BUFFERSIZE;
//    DWORD  dwBytesToWrite = 0;
//    DWORD  dwBytesToCompare = 0;
//
//    char   *DataBuffer = (char *)malloc(BUFFERSIZE);
//    char   *DataBufferDest = (char *)malloc(BUFFERSIZE);
//
//
//
//    ULONGLONG ullVolumeOffset = 0;
//    OVERLAPPED ol = { 0 };
//    ULONGLONG blkno = 0;
//    BYTE databyte = 0;
//    ULONG bitmapSizeInBytes;
//    ULONG dirtyBlocks = 0;
//    int gretval = CBT_SUCCESS;
//    HANDLE hSrcVolume;
//    HANDLE hDstVolume;
//
//    hSrcVolume = OpenSourceVolume(src_vol_path);
//    hDstVolume = OpenDestinationVolume(dest_vol_path);
//
//    if (hSrcVolume != INVALID_HANDLE_VALUE && hDstVolume != INVALID_HANDLE_VALUE)
//    {
//
//        PUCHAR bitmapBuffer = src_volbitmapbuffer;//cbtGetBitmap(argv[4], &bitmapSizeInBytes);
//        bitmapSizeInBytes = src_volbitmap_size;
//
//        if (bitmapBuffer) {
//            blkno = 0;
//            for (ULONG i = 0; i < bitmapSizeInBytes; i++)
//            {
//                databyte = bitmapBuffer[i];
//
//                for (int b = 0; b < 8; b++)
//                {
//                    if (databyte & (1 << b))
//                    {
//                        ullVolumeOffset = blkno * 4096ULL;
//
//                        cscbtSetVolumeOffset(hSrcVolume, ullVolumeOffset);
//                        cscbtSetVolumeOffset(hDstVolume, ullVolumeOffset);
//
//                        printf("ullFileOffset %I64d\n", ullVolumeOffset);
//
//                        dwBytesToRead = 4096;
//
//                        if (cscbtReadData(hSrcVolume, DataBuffer, dwBytesToRead, &dwBytesToWrite) == FALSE) {
//
//
//                            printf("\n Failed to read from src file [err 0x%x]\n", GetLastError());
//                            //DisplayError(L"Main", GetLastError());
//                            ::OutputDebugString(L"Failed to read from src file");
//                            exit(1);
//
//                        }
//                        else {
//
//                            if (dwBytesToWrite == 0) {
//                                printf("\n\n  Restore Finished\n\n\n");
//                                ::OutputDebugString(L"Restore Finished");
//
//                                exit(0);
//                            }
//
//
//                            if (cscbtWriteData(hDstVolume, DataBuffer, dwBytesToWrite) == FALSE) {
//                                //DisplayError(L"Main", GetLastError());
//                                printf("Failed to write from dst file [err 0x%x]\n", GetLastError());
//                                ::OutputDebugString(L"Failed to write from dst file");
//
//                                exit(1);
//                            }
//                        }
//                        dirtyBlocks++;
//                        printf("Copying dirtyBlockNo = %I64d (%.2f MB copied) cscbtSetFileOffset %I64u\n", blkno, (double)((double)dirtyBlocks*(double)4096) / double(1024 * 1024), ullVolumeOffset);
//
//                    }
//                    ullVolumeOffset = blkno * 4096ULL;
//                    blkno++;
//                }
//            }
//
//            printf("\n\n  Copy Finished: bitmapSizeInBytes %d block %I64d\n\n\n", bitmapSizeInBytes, blkno);
//
//        }
//    }
//    else {
//        printf("Failed to open volume \n");
//    }
//}
//
//ULONG cscbtGetFileBitmap(TCHAR *filepath, PUCHAR *pFileBitmap)
//{
//    DWORD bytesRead = 0;
//    PUCHAR buff = (PUCHAR)malloc(4096);
//    PUCHAR buff_zero = (PUCHAR)malloc(4096);
//    int fblkCount = 0;
//    int fby = 0;
//    int fbi = 0;
//    DWORD fileSize2 = 0;
//    DWORD fileSize = 0;
//    HANDLE hSrcVolume = NULL;
//    ULONG fileBitmapSizeInBytes = 0;
//    PUCHAR fileBitmap = NULL;
//
//    memset(buff_zero, 0, 4096);
//
//    hSrcVolume = OpenSourceVolume(filepath);
//
//    if (hSrcVolume != INVALID_HANDLE_VALUE)
//    {
//        fileSize = GetFileSize(hSrcVolume, &fileSize2);
//        fileBitmapSizeInBytes = (fileSize / 4096) / 8;
//        fileBitmap = (PUCHAR)malloc((fileBitmapSizeInBytes));
//        memset(fileBitmap, 0, fileBitmapSizeInBytes);
//        do {
//            memset(buff, 0, 4096);
//            cscbtSetFileOffset(hSrcVolume, fblkCount * 4096, FILE_BEGIN);
//            ReadFile(hSrcVolume, buff, 4096, &bytesRead, NULL);
//            if (bytesRead == 0) {
//                printf("cscbtGetFileBitmap Read %.02f\n", (((float)fblkCount*(float)4096)) / (float)1024);
//                break;
//            }
//
//            if (memcmp(buff, buff_zero, bytesRead) != 0)
//            {
//                fby = (fblkCount) / 8;
//                fbi = (fblkCount) % 8;
//                fileBitmap[fby] |= (0x1 << fbi);
//                //      printf("fbitmap[%d][%d] == 1\n", fby,fbi);
//            }
//            else {
//                //          printf("fbitmap[%d][%d] == 0\n", fby,fbi);
//            }
//
//            fblkCount++;
//
//        } while (1);
//        CloseHandle(hSrcVolume);
//    }
//
//    *pFileBitmap = fileBitmap;
//    return fileBitmapSizeInBytes;
//}
//
//LONGLONG GetFilePointerEx(HANDLE hFile);
//
//BOOL cscbtSetFileOffset(HANDLE hHandle, ULONGLONG ullOffset, ULONG StartFromFlag)
//{
//
//    LARGE_INTEGER liOffset = { 0 };
//    liOffset.QuadPart = ullOffset;
//    DWORD dwOffsetPtr;
//
//    dwOffsetPtr = SetFilePointer(hHandle,
//        liOffset.LowPart,
//        &liOffset.HighPart,
//        StartFromFlag);
//
//    if (dwOffsetPtr == INVALID_SET_FILE_POINTER || -1 == dwOffsetPtr)
//    {
//        printf("  File : cscbtSetFileOffset Error = \n");
//        DisplayError(L"cscbtSetFileOffset", GetLastError());
//        gretval = CBT_ERROR;
//        return FALSE;
//    }
//
//    GetFilePointerEx(hHandle);
//
//    return TRUE;
//
//}
//
//LONGLONG GetFilePointerEx(HANDLE hFile) {
//    LARGE_INTEGER liOfs = { 0 };
//    LARGE_INTEGER liNew = { 0 };
//    SetFilePointerEx(hFile, liOfs, &liNew, FILE_CURRENT);
//    return liNew.QuadPart;
//}
//
//ULONG cscbtGetVHDHeaders(TCHAR *vhdfilepath)
//{
//
//    HARD_DISK_FOOTER    HardDiskFooterBigEndian;
//    DYNAMIC_DISK_HEADER DynamicDiskHeaderBigEndian;
//    PULONG BATBigEndian = NULL;
//    //ULONG BATBigEndian[1024];
//    ULONG ullFirstBlockBitmapAddr = 0;
//    ULONG ullMbrAddr = 0;
//    HANDLE hFile;
//    ULONG dwBytesRead = 0;
//    ULONG  checksum = 0;
//    ULONG tmpChkSum = 0;
//
//    //fopen_s(&fd, vhdfilepath, "rb+");
//
//    PBYTE pByte;
//
//    hFile = OpenSourceVolume(vhdfilepath);
//
//    if (hFile != INVALID_HANDLE_VALUE) {
//        cscbtSetFileOffset(hFile, -512, FILE_END);
//        cscbtReadData(hFile, (CHAR *)&HardDiskFooterBigEndian, sizeof(HARD_DISK_FOOTER), &dwBytesRead);
//        memcpy(&gHardDiskFooter, &HardDiskFooterBigEndian, sizeof(HARD_DISK_FOOTER));
//
//    }
//    else {
//        DisplayError(TEXT("open failed"), GetLastError());
//        printf("failed to open vhd file\n");
//        return -1;
//    }
//
//    // swap big to little endian
//    gHardDiskFooter.ullCookie = _byteswap_uint64(HardDiskFooterBigEndian.ullCookie);
//    gHardDiskFooter.ulFeatures = _byteswap_ulong(HardDiskFooterBigEndian.ulFeatures);
//    gHardDiskFooter.ulFileFormatVersion = _byteswap_ulong(HardDiskFooterBigEndian.ulFileFormatVersion);
//    gHardDiskFooter.ullDataOffset = _byteswap_uint64(HardDiskFooterBigEndian.ullDataOffset);
//    gHardDiskFooter.ulTimeStamp = _byteswap_ulong(HardDiskFooterBigEndian.ulTimeStamp);
//    gHardDiskFooter.ulCreatorApplication = _byteswap_ulong(HardDiskFooterBigEndian.ulCreatorApplication);
//    gHardDiskFooter.ulCreatorVersion = _byteswap_ulong(HardDiskFooterBigEndian.ulCreatorVersion);
//    gHardDiskFooter.ulCreatorHostOS = _byteswap_ulong(HardDiskFooterBigEndian.ulCreatorHostOS);
//    gHardDiskFooter.ullOriginalSize = _byteswap_uint64(HardDiskFooterBigEndian.ullOriginalSize);
//    gHardDiskFooter.ullCurrentSize = _byteswap_uint64(HardDiskFooterBigEndian.ullCurrentSize);
//    gHardDiskFooter.usDiskGeometryCylinder = _byteswap_ushort(HardDiskFooterBigEndian.usDiskGeometryCylinder);
//    gHardDiskFooter.ulDiskType = _byteswap_ulong(HardDiskFooterBigEndian.ulDiskType);
//    gHardDiskFooter.ulChecksum = 0;//_byteswap_ulong(HardDiskFooterBigEndian.ulChecksum);
//    gHardDiskFooter.ulReserved = _byteswap_ulong(HardDiskFooterBigEndian.ulReserved);
//    for (int i = 0; i < 16; i++)
//    {
//        gHardDiskFooter.ucUniqueId[i] = HardDiskFooterBigEndian.ucUniqueId[i];
//    }
//    gHardDiskFooter.ucSavedState = HardDiskFooterBigEndian.ucSavedState;
//
//    ULONG tmpCheckcum = _byteswap_ulong(HardDiskFooterBigEndian.ulChecksum);
//    pByte = (PBYTE)&gHardDiskFooter;
//
//
//    for (ULONG counter = 0; counter < sizeof(HARD_DISK_FOOTER); counter++)
//    {
//        checksum += pByte[counter];
//    }
//
//   gHardDiskFooter.ulChecksum = ~checksum;
//   if (tmpCheckcum != gHardDiskFooter.ulChecksum)
//   {
//       printf("File is not VHD");
//       return 0;
//   }
//
//   if (gHardDiskFooter.ulDiskType == DYNAMIC_HARD_DISK) {
//
//       printf("== Dynamic VHD Disk ==\n");
//
//       cscbtSetFileOffset(hFile, gHardDiskFooter.ullDataOffset, FILE_BEGIN);
//       cscbtReadData(hFile, (CHAR *)&DynamicDiskHeaderBigEndian, sizeof(DYNAMIC_DISK_HEADER), &dwBytesRead);
//
//       // Dynamic Disk Header - Little Endian
//       memcpy(&gDynamicDiskHeader, &DynamicDiskHeaderBigEndian, sizeof(DYNAMIC_DISK_HEADER));
//
//       gDynamicDiskHeader.ullCookie = _byteswap_uint64(DynamicDiskHeaderBigEndian.ullCookie);
//       gDynamicDiskHeader.ullDataOffset = _byteswap_uint64(DynamicDiskHeaderBigEndian.ullDataOffset);
//       gDynamicDiskHeader.ullTableOffset = _byteswap_uint64(DynamicDiskHeaderBigEndian.ullTableOffset);
//       gDynamicDiskHeader.ulHeaderVersion = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulHeaderVersion);
//       gDynamicDiskHeader.ulMaxTableEntries = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulMaxTableEntries);
//       gDynamicDiskHeader.ulBlockSize = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulBlockSize);
//       gDynamicDiskHeader.ulChecksum = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulChecksum);
//       gDynamicDiskHeader.ulParentTimeStamp = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulParentTimeStamp);
//       gDynamicDiskHeader.ulReserved = _byteswap_ulong(DynamicDiskHeaderBigEndian.ulReserved);
//
//       // double MaxEntries = ceil((double)gHardDiskFooter.ullOriginalSize / ((double)gDynamicDiskHeader.ulBlockSize -512));
//
//        //////////////////
//
//       BATBigEndian = (PULONG)calloc(gDynamicDiskHeader.ulMaxTableEntries, sizeof(ULONG));
//       if (!BATBigEndian) printf("Error allocating memory\n");
//
//       gBAT = (PULONG)calloc(gDynamicDiskHeader.ulMaxTableEntries, sizeof(ULONG));
//       if (!gBAT) printf("Error allocating memory\n");
//
//       cscbtSetFileOffset(hFile, gDynamicDiskHeader.ullTableOffset, FILE_BEGIN);
//       cscbtReadData(hFile, (CHAR *)BATBigEndian, gDynamicDiskHeader.ulMaxTableEntries * sizeof(ULONG), &dwBytesRead);
//
//        // Block Allocation Table - Little Endian
//        for (int i = 0; i<gDynamicDiskHeader.ulMaxTableEntries; i++)
//        {
//            gBAT[i] = _byteswap_ulong(BATBigEndian[i]);
//
//            //printf("gBAT[%d] = %x %d mod=%d\n" , i, gBAT[i]*512, gBAT[i]*512, (gBAT[i] * 512 % 4096));
//            //if (gBAT[i] != 0xFFFFFFFF) {
//                //printf("gBAT[%d] = %x %d\n", i, gBAT[i], gBAT[i]);
//            //printf("%d\n", gBAT[i]);
//            //}
//        }
//
//        ULONGLONG ullBATStart = 0x600;//1536
//        ULONGLONG ullBATEnd = 0;
//        ULONGLONG ullBATSize = 0;
//        //ULONGLONG ullFileFinalSize = 0;
//        LARGE_INTEGER ullFileFinalSize;
//        ullFileFinalSize.QuadPart = 0;
//
//        if (gBAT[0] == 0xFFFFFFFF)
//        {
//            cscbtSetFileOffset(hFile, -512, FILE_END);
//            ullBATEnd = GetFilePointerEx(hFile);
//            ullBATSize = ullBATEnd - ullBATStart;
//        }
//        else
//        {
//            ullBATEnd = gBAT[0] * 512;
//            ullBATSize = ullBATEnd - ullBATStart;
//        }
//
//        ullFileFinalSize.QuadPart = ((uint64_t)DISK_MIRROR_FOOTER + (uint64_t)DISK_HEADER + (uint64_t)ullBATSize + ((uint64_t)gDynamicDiskHeader.ulMaxTableEntries * (uint64_t)DISK_2MB_ALLGIN) +
//                            ((uint64_t)gDynamicDiskHeader.ulMaxTableEntries * (uint64_t)DISK_4K_ALLIGN) + (uint64_t)DISK_FOOTER);
//      /*  uint64_t MHdr = 512;
//        uint64_t Hdr = 1024;
//        uint64_t BAT = 1030144;
//        uint64_t DataBlocks = (uint64_t)((uint64_t)256000 * (uint64_t)2 * (uint64_t)1024 * (uint64_t)1024);
//        uint64_t Padding = 256000 * 4096;
//        uint64_t Footer = 512;
//
//
//        ullFileFinalSize.QuadPart = MHdr;
//        ullFileFinalSize.QuadPart += Hdr;
//        ullFileFinalSize.QuadPart += BAT;
//        ullFileFinalSize.QuadPart += DataBlocks;
//        ullFileFinalSize.QuadPart += Padding;
//        ullFileFinalSize.QuadPart += Footer;*/
//        printf("ullFileFinalSize == %I64u\n", ullFileFinalSize.QuadPart);
//
//
//        // Master Boot Record
//        //Read first block bitmap from (BAT[0] * VHD_SECTOR_SIZE)
//        ullFirstBlockBitmapAddr = gBAT[0] * VHD_SECTOR_SIZE; // first entry of the block is bitmap
//
//                                                             //the very first sector of the first block data is MBR Address
//        ullMbrAddr = ullFirstBlockBitmapAddr + VHD_SECTOR_SIZE;
//
//        cscbtSetFileOffset(hFile, ullMbrAddr, FILE_BEGIN);
//        cscbtReadData(hFile, (CHAR *)&gDiskMbr, sizeof(DISK_MBR), &dwBytesRead);
//
//
//    }
//    else {
//
//
//        printf("== fixed VHD Disk ==\n");
//
//        // Master Boot Record
//        //Read first block bitmap from (BAT[0] * VHD_SECTOR_SIZE)
//        ullFirstBlockBitmapAddr = 0 * VHD_SECTOR_SIZE; // first entry of the block is bitmap
//
//                                                       //the very first sector of the first block data is MBR Address
//        ullMbrAddr = ullFirstBlockBitmapAddr;
//
//        cscbtSetFileOffset(hFile, ullMbrAddr, FILE_BEGIN);
//        cscbtReadData(hFile, (CHAR *)&gDiskMbr, sizeof(DISK_MBR), &dwBytesRead);
//
//    }
//
//    CloseHandle(hFile);
//
//
//    return gHardDiskFooter.ulDiskType;
//}
//
//
//
//
//ULONG cscbtGetVolumeBitmap(char *vhdfilepath, ULONG ulPartitionOffset, ULONG ulBitmapHandle, PUCHAR *pVolBitmap, PUCHAR fileBitmap, ULONG ulDiskType)
//{
//    ULONGLONG ullVolAbsoluteSector;
//    ULONGLONG ullVolAbsoluteStartSector = gDiskMbr.MbrPartition[ulPartitionOffset].ulfirstAbsoluteSectorLba;
//    ULONGLONG ullVolAbsoluteEndSector = gDiskMbr.MbrPartition[ulPartitionOffset].ulfirstAbsoluteSectorLba + gDiskMbr.MbrPartition[ulPartitionOffset].ulNoOfSectors;
//    ULONG ulTotalNoOfSectors = gDiskMbr.MbrPartition[ulPartitionOffset].ulNoOfSectors;
//    ULONGLONG ullVolSizeInBytes = (gDiskMbr.MbrPartition[ulPartitionOffset].ulNoOfSectors * 512);
//    ULONG     ulVolBitmapSizeInBytes = (ullVolSizeInBytes / 4096) / 8;
//    PUCHAR    volBitmap = (PUCHAR)malloc(ulVolBitmapSizeInBytes);
//
//    memset(volBitmap, 0, ulVolBitmapSizeInBytes);
//
//    ULONG ulSectorsPerBlock = 4096;
//    ULONG ulBATindex = 0;
//    ULONG ulSectorInBlock = 0;
//    ULONGLONG ullVHDSector;
//    ULONGLONG ullVHDSectorAddr;
//
//    ULONG fby = 0;
//    ULONG fbi = 0;
//    ULONG fblkno = 0;
//
//    ULONG vby = 0;
//    ULONG vbi = 0;
//    ULONG vblkno = 0;
//
//
//    ullVolAbsoluteSector = ullVolAbsoluteStartSector;
//    for (int i = 0; i<ulTotalNoOfSectors; i += 8) // jump 8 sectors = 8 x 512 = 4K
//    {
//
//        if (ulDiskType == DYNAMIC_HARD_DISK) {
//
//            ulBATindex = ullVolAbsoluteSector / ulSectorsPerBlock;
//            ulSectorInBlock = ullVolAbsoluteSector % ulSectorsPerBlock;
//
//            ullVHDSector = gBAT[ulBATindex] + 1 + ulSectorInBlock;
//            ullVHDSectorAddr = ullVHDSector * VHD_SECTOR_SIZE;
//
//        }
//        else {
//
//            ullVHDSector = ullVolAbsoluteSector;
//            ullVHDSectorAddr = ullVHDSector * VHD_SECTOR_SIZE;
//            ullVolAbsoluteSector += 8; // jump to next 8 sectors
//
//        }
//
//        if ((ullVHDSectorAddr & 0xFFF)) {
//            printf("*** UNALIGNED ullVHDSectorAddr = %I64x BAT[%d][%d] = %I64d\n", ullVHDSectorAddr, ulBATindex, ulSectorInBlock, ullVHDSector);
//        }
//
//        fblkno = ((ullVHDSectorAddr & 0xFFF) / 4096);
//        fby = (fblkno) / 8;
//        fbi = (fblkno) % 8;
//
//        if (fileBitmap[fby] & (0x1 << fbi))
//        {
//            vblkno = ((i * 512) / 4096);
//            vby = (vblkno) / 8;
//            vbi = (vblkno) % 8;
//
//            volBitmap[vby] |= (0x1 << vbi);
//        }
//
//        //printf("{%d} ullVolAbsoluteSector %I64d / %I64d BAT[%d][%d] \n",ulTotalNoOfSectors, ullVolAbsoluteSector, (ullVolAbsoluteStartSector + ulTotalNoOfSectors),
//        //  ulBATindex, ulSectorInBlock);
//
//        ullVolAbsoluteSector += 8;
//    }
//
//    *pVolBitmap = volBitmap;
//
//    return ulVolBitmapSizeInBytes;
//
//
//}



//#include <windows.h>
//#include <tlhelp32.h>
//#include <tchar.h>
//
////  Forward declarations:
//BOOL GetProcessList( );
//BOOL ListProcessModules( DWORD dwPID );
//BOOL ListProcessThreads( DWORD dwOwnerPID );
//void printError( TCHAR* msg );
//
//int main( void )
//{
//  GetProcessList( );
//  return 0;
//}
//
//BOOL GetProcessList( )
//{
//  HANDLE hProcessSnap;
//  HANDLE hProcess;
//  PROCESSENTRY32 pe32;
//  DWORD dwPriorityClass;
//
//  // Take a snapshot of all processes in the system.
//  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
//  if( hProcessSnap == INVALID_HANDLE_VALUE )
//  {
//    printError( TEXT("CreateToolhelp32Snapshot (of processes)") );
//    return( FALSE );
//  }
//
//  // Set the size of the structure before using it.
//  pe32.dwSize = sizeof( PROCESSENTRY32 );
//
//  // Retrieve information about the first process,
//  // and exit if unsuccessful
//  if( !Process32First( hProcessSnap, &pe32 ) )
//  {
//    printError( TEXT("Process32First") ); // show cause of failure
//    CloseHandle( hProcessSnap );          // clean the snapshot object
//    return( FALSE );
//  }
//
//  // Now walk the snapshot of processes, and
//  // display information about each process in turn
//  do
//  {
//    _tprintf( TEXT("\n\n=====================================================" ));
//    _tprintf( TEXT("\nPROCESS NAME:  %s"), pe32.szExeFile );
//    _tprintf( TEXT("\n-------------------------------------------------------" ));
//
//    // Retrieve the priority class.
//    dwPriorityClass = 0;
//    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );
//    if( hProcess == NULL )
//      printError( TEXT("OpenProcess") );
//    else
//    {
//      dwPriorityClass = GetPriorityClass( hProcess );
//      if( !dwPriorityClass )
//        printError( TEXT("GetPriorityClass") );
//      CloseHandle( hProcess );
//    }
//
//    _tprintf( TEXT("\n  Process ID        = 0x%08X"), pe32.th32ProcessID );
//    _tprintf( TEXT("\n  Thread count      = %d"),   pe32.cntThreads );
//    _tprintf( TEXT("\n  Parent process ID = 0x%08X"), pe32.th32ParentProcessID );
//    _tprintf( TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase );
//    if( dwPriorityClass )
//      _tprintf( TEXT("\n  Priority class    = %d"), dwPriorityClass );
//
//    // List the modules and threads associated with this process
//    ListProcessModules( pe32.th32ProcessID );
//    ListProcessThreads( pe32.th32ProcessID );
//
//  } while( Process32Next( hProcessSnap, &pe32 ) );
//
//  CloseHandle( hProcessSnap );
//  return( TRUE );
//}
//
//
//BOOL ListProcessModules( DWORD dwPID )
//{
//  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
//  MODULEENTRY32 me32;
//
//  // Take a snapshot of all modules in the specified process.
//  hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
//  if( hModuleSnap == INVALID_HANDLE_VALUE )
//  {
//    printError( TEXT("CreateToolhelp32Snapshot (of modules)") );
//    return( FALSE );
//  }
//
//  // Set the size of the structure before using it.
//  me32.dwSize = sizeof( MODULEENTRY32 );
//
//  // Retrieve information about the first module,
//  // and exit if unsuccessful
//  if( !Module32First( hModuleSnap, &me32 ) )
//  {
//    printError( TEXT("Module32First") );  // show cause of failure
//    CloseHandle( hModuleSnap );           // clean the snapshot object
//    return( FALSE );
//  }
//
//  // Now walk the module list of the process,
//  // and display information about each module
//  do
//  {
//    _tprintf( TEXT("\n\n     MODULE NAME:     %s"),   me32.szModule );
//    _tprintf( TEXT("\n     Executable     = %s"),     me32.szExePath );
//   // _tprintf( TEXT("\n     Process ID     = 0x%08X"),         me32.th32ProcessID );
//    _tprintf( TEXT("\n     Process ID     = %d"),         me32.th32ProcessID );
//	_tprintf( TEXT("\n     Ref count (g)  = 0x%04X"),     me32.GlblcntUsage );
//    _tprintf( TEXT("\n     Ref count (p)  = 0x%04X"),     me32.ProccntUsage );
//    _tprintf( TEXT("\n     Base address   = 0x%08X"), (DWORD) me32.modBaseAddr );
//    _tprintf( TEXT("\n     Base size      = %d"),             me32.modBaseSize );
//
//  } while( Module32Next( hModuleSnap, &me32 ) );
//
//  CloseHandle( hModuleSnap );
//  return( TRUE );
//}
//
//BOOL ListProcessThreads( DWORD dwOwnerPID )
//{
//  HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
//  THREADENTRY32 te32;
//
//  // Take a snapshot of all running threads
//  hThreadSnap = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 );
//  if( hThreadSnap == INVALID_HANDLE_VALUE )
//    return( FALSE );
//
//  // Fill in the size of the structure before using it.
//  te32.dwSize = sizeof(THREADENTRY32);
//
//  // Retrieve information about the first thread,
//  // and exit if unsuccessful
//  if( !Thread32First( hThreadSnap, &te32 ) )
//  {
//    printError( TEXT("Thread32First") ); // show cause of failure
//    CloseHandle( hThreadSnap );          // clean the snapshot object
//    return( FALSE );
//  }
//
//  // Now walk the thread list of the system,
//  // and display information about each thread
//  // associated with the specified process
//  do
//  {
//    if( te32.th32OwnerProcessID == dwOwnerPID )
//    {
//      _tprintf( TEXT("\n\n     THREAD ID      = 0x%08X"), te32.th32ThreadID );
//      _tprintf( TEXT("\n     Base priority  = %d"), te32.tpBasePri );
//      _tprintf( TEXT("\n     Delta priority = %d"), te32.tpDeltaPri );
//      _tprintf( TEXT("\n"));
//    }
//  } while( Thread32Next(hThreadSnap, &te32 ) );
//
//  CloseHandle( hThreadSnap );
//  return( TRUE );
//}
//
//void printError( TCHAR* msg )
//{
//  DWORD eNum;
//  TCHAR sysMsg[256];
//  TCHAR* p;
//
//  eNum = GetLastError( );
//  FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
//         NULL, eNum,
//         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
//         sysMsg, 256, NULL );
//
//  // Trim the end of the line and terminate it with a null
//  p = sysMsg;
//  while( ( *p > 31 ) || ( *p == 9 ) )
//    ++p;
//  do { *p-- = 0; } while( ( p >= sysMsg ) &&
//                          ( ( *p == '.' ) || ( *p < 33 ) ) );
//
//  // Display the message
//  _tprintf( TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg );
//}


//#include <iostream>
//#include <unordered_set>
//using namespace std;
//
//struct node{
//
//	int data;
//	struct node *left;
//	struct node *right;
//};
//
//unordered_set<int>g_uset;
//struct node *newNode(int val)
//{
//	struct node *tmp;
//	tmp = (struct node*)malloc(sizeof(struct node));
//	tmp->data = val;
//	tmp->left = NULL;
//	tmp->right = NULL;
//	return tmp;
//
//}
//
//void InOrder(struct node *ptr)
//{
//	if(ptr == NULL)
//		return;
//
//	InOrder(ptr->left);
//	cout<<ptr->data<<" ";
//	g_uset.insert(ptr->data);
//	InOrder(ptr->right);
//
//}
//
//bool FindPairInTree(struct node *ptr,int sum,unordered_set<int>&uset )
//{
//	if(ptr == NULL)
//		return false;
//
//	FindPairInTree(ptr->left,sum,uset);
//
//	if(uset.find(sum - ptr->data)!= uset.end())
//	{
//		cout<<"Pair Found : "<<"("<<sum - ptr->data
//			<<","<<ptr->data<<")"<<endl;
//		return true;
//	}
//
//	FindPairInTree(ptr->right,sum,uset);
//
//}
//
//int main()
//{
//	int sum = 15;
//	struct node *root;
//	root = newNode(2);
//	root->left = newNode(10);
//	root->right = newNode(6);
//	root->left->left = newNode(5);
//	root->left->right = newNode(8);
//	root->right->left = newNode(13);
//	root->right->right = newNode(4);
//	root->left->right->left =newNode(45);
//
//
//	cout<<"InOrder : ";
//	InOrder(root);
//	cout<<endl;
//	cout<<"FindPairInTree : ";
//	FindPairInTree(root,sum,g_uset);
//	cout<<endl;
//
//	return 0;
//}


//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int main() {
//    // Complete the code.
//    int a,b;
//    cout<<"Enter two nos. : ";
//    cin>>a;
//    cin>>b;
//    cout<<endl;
//    for(int i = a;i<=b;i++)
//    {
//            if(i == 1)
//                cout<<"one"<<endl;
//            else if(i == 2)
//                cout<<"two"<<endl;
//            else if(i == 3)
//                cout<<"three"<<endl;
//            else if(i == 4)
//                cout<<"four"<<endl;
//            else if(i == 5)
//                cout<<"five"<<endl;
//            else if(i == 6)
//                cout<<"six"<<endl;
//            else if(i == 7)
//                cout<<"seven"<<endl;
//            else if(i == 8)
//                cout<<"eight"<<endl;
//            else if(i == 9)
//                cout<<"nine"<<endl;
//    }
//
// for(int i = a;i<=b;i++)
//   {
//       if(a<=9)
//       {
//           if(a % 2 == 0)
//               cout<<"even"<<endl;
//           else
//               cout<<"odd"<<endl;
//       }
//   }
//    return 0;
//}



//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n;
//    vector<int>vect;
//    cin>>n;
//    for(int j =0;j<n;j++)
//    {
//        int num;
//        cin>>num;
//       for(int i = 0;i<num; i++)
//       {
//           int val;
//           cin>>val;
//            vect.push_back(val);
//
//       }
//        if(j == 0)
//               cout<<vect.at(1)<<endl;
//       else if(j == 1)
//           cout<<vect.at(3)<<endl;
//    }
//    return 0;
//}


//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int num1;
//    int num2;
//    cin>>num1;
//    cin>>num2;
//
//	vector<int >vect1;
//	vector<int >vect2;
//
//
//
//    for(int i =0;i<num1;i++)
//    {
//        int val;
//        cin>>val;
//
//        vect1.push_back(val);
//
//    }
//    for(int i =0;i<num2;i++)
//    {
//        int val;
//        cin>>val;
//
//        vect2.push_back(val);
//
//    }
//
//    cout<<vect1[1]<<endl;
//    cout<<vect2[3]<<endl;
//   return 0;
//}




//#include<iostream>
//
//using namespace std;
//
//int callA=0;
//int callB=0;
//int callC=0;
//class A
//{
//protected:
//
//	void func(int  & a)
//	{
//	  a=a*2;
//	  callA++;
//	}
//};
//
//class B
//{
//protected:
//	void func(int & a)
//	{
//	  a=a*3;
//	  callB++;
//	}
//};
//
//class C
//{
//protected:
//	void func(int & a)
//	{
//	  a=a*5;
//	  callC++;
//	}
//};
//
//class D : public A,B,C
//{
//	int val;
//	public:
//		//Initially val is 1
//		D()
//		{
//			val=1;
//		}
//
//		//Implement this function
//		void update_val(int new_val)
//		{
//			for(;new_val%2==0;new_val/=2)A::func(val);
//			for(;new_val%3==0;new_val/=3)B::func(val);
//			for(;new_val%5==0;new_val/=5)C::func(val);
//		}
//		//For Checking Purpose
//		void check(int); //Do not delete this line.
//};
//
//void D::check(int new_val)
//{
//	update_val(new_val);
//	cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
//}
//
//int main()
//{
//	D d;
//	int new_val;
//	cin>>new_val;
//	d.check(new_val);
//}


//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Display() = 0;
//	void Show()
//	{
//		cout<<"Base : Show"<<endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	void Display()
//	{
//		cout<<"Derived : Display"<<endl;
//	}
//
//	void Print()
//	{
//		cout<<"Derived  Print"<<endl;
//	}
//};
//
//
//int main()
//{
//	Base *b;
//	Base *bPtr = new Derived();
//	bPtr->Display();
//	bPtr->Show();
//
//
//	return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Base
//{
//
//public:
//	Base()
//	{
//		cout<<"Default Constructor"<<endl;
//	}
//
//	Base(const Base &b)
//	{
//		cout<<"Copy Constructor"<<endl;
//	}
//
//	Base& operator =(const Base &b)
//	{
//		cout<<"Assignment Operator"<<endl;
//	}
//};
//
//int main()
//{
//	vector<Base>vect;
//	Base b;
//	vect.push_back(b);
//
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//
//	vector<int>vect;
//	vect.push_back(1);
//	vect.push_back(5);
//	vect.push_back(5);
//	vect.push_back(8);
//	vect.push_back(9);
//	vect.push_back(7);
//	vect.push_back(9);
//	vect.push_back(6);
//
//
//	for_each(vect.begin(),vect.end(),[](int x)
//	{
//		cout<<x<<" ";
//	});
//
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//class Base
//{
//
//public:
//	Base()
//	{
//		cout<<"Default : Constructor "<<endl;
//	}
//
//	Base(Base &&obj)
//	{
//		cout<<"Move : Constructor"<<endl;
//	}
//
//	Base &operator = (Base &&obj)
//	{
//		cout<<"Move : Assignment"<<endl;
//	}
//};
//
//int main()
//{
//	Base obj;
//	Base obj1 = move(obj);
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//int main() {
//	//code
//	//int num;
//
//	///cin>>num;
//
//	int arr[5];
//
//	for(int i =0;i<5;i++)
//	{
//	    int n;
//	    cin>>n;
//
//	    arr[i] = n;
//
//	}
//
//	int total;
//	int len = sizeof(arr)/sizeof(arr[0]);
//	total = (len * len) + len;
//	total  /=2;
////  total = (len(len + 1 ))/2;
//
//	int sum = 0;
//	for(int i =0;i<5;i++)
//	{
//	    sum +=arr[i];
//
//	}
//	int temp;
//	temp = total - sum;
//
//	cout<<"Missing element : "<<temp<<endl;
//	return 0;
//
//
//}



//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//	Singleton()
//	{
//		cout<<"Private : Constructor"<<endl;
//	}
//
//	static bool bIsInstance;
//	static Singleton *single;
//public:
//	~Singleton()
//	{
//		cout<<"Singleton : Destructor"<<endl;
//	}
//	void method();
//	static Singleton* getInstance();
//
//};
//
//Singleton *Singleton:: single = NULL;
//bool Singleton::bIsInstance = false;
//Singleton *Singleton::getInstance()
//{
//	if(bIsInstance == false)
//	{
//		single = new Singleton();
//		return single;
//	}
//	else
//		return single;
//}
//
//void Singleton::method()
//{
//	cout<<"Singleton : Method"<<endl;
//}
//
//int main()
//{
//	Singleton *sc = Singleton::getInstance();
//	sc->method();
//
//	return 0;
//}



//#include <iostream>
//
//struct node
//{
//	int data;
//	struct node *link;
//}*head = NULL;
//
//
//void CreateLL()
//{
//	int n,val;
//	struct node *current,*tmp;
//	cout<<"Enter no. of nodes : ";
//	cin>>n;
//	cout<<endl;
//	for(int i =0;i<n;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>val;
//		tmp = (struct node*)malloc(sizeof(struct node));
//		tmp->data = val;
//		tmp->link = NULL;
//
//		if(head == NULL)
//		{
//			head = tmp;
//			current = tmp;
//		}
//		else
//		{
//			while(current->link != NULL)
//				current = current->link;
//
//			current->link = tmp;
//			current = tmp;
//		}
//
//	}
//}
//
//void DisplayLL()
//{
//
//	struct node *ptr;
//	if(head == NULL)
//		return;
//
//	ptr = head;
//
//	while(ptr != NULL)
//	{
//		cout<<ptr->data<<" ";
//		ptr = ptr->link;
//	}
//
//
//}
//
//
//void FindMiddleElemInLL()
//{
//	struct node *ptr1 = head;
//	struct node *ptr2 = head;
//
//	if(head != NULL )
//	{
//		while(ptr2!= NULL && ptr2->link != NULL)
//		{
//			ptr2 = ptr2->link->link;
//			ptr1 = ptr1->link;
//		}
//
//		cout<<"Middle element in LL : "<<ptr1->data<<endl;
//	}
//}
//
//int main()
//{
//	cout<<"CreateLL : ";
//	CreateLL();
//	cout<<endl;
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//	cout<<"FindMiddleElemInLL : ";
//	FindMiddleElemInLL();
//	cout<<endl;
//
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//void Swap(int *a, int *b)
//{
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void BubbleSort(int arr[],int n)
//{
//	for(int i =0;i<n-1;i++)
//	{
//		for(int j =0;j<n-1-i;j++)
//			if(arr[j] > arr[j+1])
//				Swap(&arr[j],&arr[j+1]);
//	}
//
//}
//
//void SelectionSort(int arr[],int n)
//{
//	for(int i =0;i<n-1;i++)
//	{
//		int min_n = i;
//		for(int j =i +1;j<n;j++)
//			if(arr[j]<arr[min_n])
//				min_n = j;
//
//		Swap(&arr[min_n],&arr[i]);
//	}
//
//}
//
//void PrintData(int arr[],int n)
//{
//	for(int i =0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//
//}
//int main()
//{
//	int arr[] = {1,5,8,2,45,7,90,4};
//
//	int n;
//
//	int a = 10;
//	int &ref = a;
//
//	n= sizeof(arr)/sizeof(arr[0]);
//
//	cout<<"Bubble Sort : ";
//	BubbleSort(arr,n);
//	PrintData(arr,n);
//	cout<<endl;
//
//	cout<<"Selection Sort : ";
//	SelectionSort(arr,n);
//	PrintData(arr,n);
//	cout<<endl;
//
//
//	return 0;
//}




//#include <iostream>
//#include "C:\Tools64\v2.0.7\protobuf-2.6.0\src\test.pb.h"
//using  namespace std;
//
//
//
//// Main function:  Reads the entire address book from a file,
////   adds one person based on user input, then writes it back out to the same
////   file.
//int main() {
//  // Verify that the version of the library that we linked against is
//  // compatible with the version of the headers we compiled against.
//  //GOOGLE_PROTOBUF_VERIFY_VERSION;
//
//  tutorial::Test* test;
//
//  cout << "Enter message: ";
//  string msg;
//  getline(cin, msg);
//  if (!msg.empty()) {
//    test->set_name(msg);
//  }
//
//
//
//  return 0;
//}


//#include <iostream>
//#include <unordered_set>
//
//using namespace std;
//
//unordered_set<int>g_uset;
//
//struct node
//{
//	int data;
//	struct node *left;
//	struct node *right;
//};
//
//
//struct node *newNode(int val)
//{
//	struct node *tmp;
//	tmp = (struct node*)malloc(sizeof(struct node));
//	tmp->data = val;
//	tmp->left = NULL;
//	tmp->right = NULL;
//	return tmp;
//
//}
//
//
//void InOrderTree(struct node *ptr)
//{
//	if(ptr == NULL)
//		return;
//	InOrderTree(ptr->left);
//	cout<<ptr->data<<" ";
//	g_uset.insert(ptr->data);
//	InOrderTree(ptr->right);
//}
//
//void FindPairInTree(struct node *ptr,int sum,unordered_set<int>&uset)
//{
//	if(ptr == NULL)
//		return;
//	FindPairInTree(ptr->left,sum,uset);
//
//	if(uset.find(sum - ptr->data)!= uset.end())
//	{
//		cout<<"Pair Find : "<<"("<<sum - ptr->data<<","<<ptr->data<<")"<<endl;
//		//return;
//	}
//
//	FindPairInTree(ptr->right,sum,uset);
//}
//
//int main()
//{
//	int sum = 20;
//	struct node *root;
//
//	root = newNode(10);
//	root->left = newNode(21);
//	root->right = newNode(12);
//	root->left->left = newNode(19);
//	root->left->right = newNode(10);
//	root->right->left = newNode(8);
//	root->right->right = newNode(6);
//
//	cout<<"InOrder : ";
//	InOrderTree(root);
//	cout<<endl;
//
//	cout<<"FindPairInTree : ";
//	FindPairInTree(root,sum,g_uset);
//	cout<<endl;
//
//
//	return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//
//	vector<int>vect;
//	vect.assign(7,100);
//
//	vector<int>::iterator it = vect.begin();
//
//	while(it != vect.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//
//	vect.push_back(23);
//	vect.push_back(1);
//	vect.push_back(87);
//	vect.push_back(23);
//	vect.push_back(6);
//	vect.push_back(21);
//
//	for(auto a :vect)
//		cout<<a<<" ";
//	cout<<endl;
//
//	cout<<"Data at 3 : "<<vect[3]<<endl;
//
//	cout<<"Vect front : "<<vect.front()<<endl;
//
//
//	vector<int>::iterator ita = vect.begin();
//
//	if(ita != vect.end())
//	{
//		if(*ita == 100)
//			vect.erase(ita);
//		else
//			ita++;
//	}
//
//	for(auto b : vect)
//		cout<<b<<" ";
//	cout<<endl;
//
//	vect.emplace(vect.begin(), 223);
//
//	vect.emplace_back(87);
//
//	cout<<"vect data : "<<vect.data()<<endl;
//	int *ptr = &vect[0];
//	cout<<"ptr : "<<*ptr<<endl;
//	int *ptr1 = &vect[1];
//	cout<<"ptr1 : "<<*ptr1<<endl;
//
//
//
//	vect[0] = 122;
//
//	for(int c : vect)
//		cout<<c<<" ";
//	cout<<endl;
//
//	vector<int>temp;
//	temp = vect;
//	temp.swap(vect);
//	for(int d :temp)
//		cout<<d<<" ";
//	cout<<endl;
//	cout<<"Size of vector : "<<vect.size()<<endl;
//	cout<<"Capacity of vector : "<<vect.capacity()<<endl;
//	cout<<"Max_size of vector : "<<vect.max_size()<<endl;
//
//	vect.reserve(100);
//
//	cout<<"Size of vector : "<<vect.size()<<endl;
//	cout<<"Capacity of vector : "<<vect.capacity()<<endl;
//	vect.insert(vect.begin(),11);
//	vect.resize(10);
//	for(auto e: vect)
//		cout<<e<<" ";
//	cout<<endl;
//	vect.shrink_to_fit();
//	for(auto f: vect)
//		cout<<f<<" ";
//	cout<<endl;
//
//	//cout<<"20th  element  : "<<vect.at(20)<<endl;
//
//	//cout<<"20th  element  : "<<vect[20]<<endl;
//
//
//	vect.pop_back();
//	vect.pop_back();
//	vect.pop_back();
//
//	cout<<"Size of vector : "<<vect.size()<<endl;
//	cout<<"Capacity of vector : "<<vect.capacity()<<endl;
//
//
//	return 0;
//}

//#include <iostream>
//#include <list>
//#include <map>
//
//using  namespace std;
//
//int main()
//{
//	list<int>mylist;
//
//	mylist.assign(5,200);
//
//	list<int>::iterator it = mylist.begin();
//
//	if(it != mylist.end())
//	{
//		cout<<*it<<" ";
//		it++;
//	}
//	cout<<endl;
//
//	mylist.push_back(12);
//	mylist.push_back(2);
//	mylist.push_back(23);
//	mylist.push_front(100);
//	mylist.push_front(45);
//
//	for(int a : mylist)
//		cout<<a<<" ";
//	cout<<endl;
//
//	mylist.emplace(mylist.end(),111);
//	mylist.emplace_back(222);
//	mylist.emplace_front(666);
//
//
//
//	for(auto b : mylist)
//		cout<<b<<" ";
//	cout<<endl;
//
//	mylist.remove(100);
//
//	/*mylist.remove_if([] (int x )
//	{
//		if(x > 100)
//			return true;
//		else
//			return false;
//	});
//
//	for(int c : mylist)
//		cout<<c<<" ";
//	cout<<endl;
//*/
//
//	mylist.push_back(22);
//	mylist.push_back(33);
//	mylist.push_back(44);
//	mylist.push_front(44);
//	mylist.push_front(22);
//
//	map<int,int>mymap;
//
//	for(auto d : mylist)
//	{
//
//		auto res = mymap.insert(pair<int,int>(d,1));
//		if(res.second == false)
//			res.first->second++;
//	}
//
//	for(auto e : mymap)
//	{
//		if(e.second > 1)
//			cout<<e.first<<" : "<<e.second<<endl;
//	}
//	return 0;
//}


//#include <windows.h>
//#include <stdio.h>
//
//#define MAX_SEM_COUNT 10
//#define THREADCOUNT 12
//
//HANDLE ghSemaphore;
//
//DWORD WINAPI ThreadProc( LPVOID );
//
//int main( void )
//{
//    HANDLE aThread[THREADCOUNT];
//    DWORD ThreadID;
//    int i;
//
//    // Create a semaphore with initial and max counts of MAX_SEM_COUNT
//
//    ghSemaphore = CreateSemaphore(
//        NULL,           // default security attributes
//        MAX_SEM_COUNT,  // initial count
//        MAX_SEM_COUNT,  // maximum count
//        NULL);          // unnamed semaphore
//
//    if (ghSemaphore == NULL)
//    {
//        printf("CreateSemaphore error: %d\n", GetLastError());
//        return 1;
//    }
//
//    // Create worker threads
//
//    for( i=0; i < THREADCOUNT; i++ )
//    {
//        aThread[i] = CreateThread(
//                     NULL,       // default security attributes
//                     0,          // default stack size
//                     (LPTHREAD_START_ROUTINE) ThreadProc,
//                     NULL,       // no thread function arguments
//                     0,          // default creation flags
//                     &ThreadID); // receive thread identifier
//
//        if( aThread[i] == NULL )
//        {
//            printf("CreateThread error: %d\n", GetLastError());
//            return 1;
//        }
//    }
//
//    // Wait for all threads to terminate
//
//    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
//
//    // Close thread and semaphore handles
//
//    for( i=0; i < THREADCOUNT; i++ )
//        CloseHandle(aThread[i]);
//
//    CloseHandle(ghSemaphore);
//
//    return 0;
//}
//
//DWORD WINAPI ThreadProc( LPVOID lpParam )
//{
//
//    // lpParam not used in this example
//    UNREFERENCED_PARAMETER(lpParam);
//
//    DWORD dwWaitResult;
//    BOOL bContinue=TRUE;
//
//    while(bContinue)
//    {
//        // Try to enter the semaphore gate.
//
//        dwWaitResult = WaitForSingleObject(
//            ghSemaphore,   // handle to semaphore
//            0L);           // zero-second time-out interval
//
//        switch (dwWaitResult)
//        {
//            // The semaphore object was signaled.
//            case WAIT_OBJECT_0:
//                // TODO: Perform task
//                printf("Thread %d: wait succeeded\n", GetCurrentThreadId());
//                bContinue=FALSE;
//
//                // Simulate thread spending time on task
//                Sleep(5);
//
//                // Release the semaphore when task is finished
//
//                if (!ReleaseSemaphore(
//                        ghSemaphore,  // handle to semaphore
//                        1,            // increase count by one
//                        NULL) )       // not interested in previous count
//                {
//                    printf("ReleaseSemaphore error: %d\n", GetLastError());
//                }
//                break;
//
//            // The semaphore was nonsignaled, so a time-out occurred.
//            case WAIT_TIMEOUT:
//                printf("Thread %d: wait timed out\n", GetCurrentThreadId());
//                break;
//        }
//    }
//    return TRUE;
//}



//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//	int a,b;
//public:
//	Base(int m,int n = 10):a(m),b(n)
//	{}
//
//	void Dipslay()
//	{
//		cout<<"A : "<<a << ","<<"B : "<<b<<endl;
//	}
//
//};
//
//int main()
//{
//	Base b(20,30);
//	b.Dipslay();
//	return 0;
//}



//#include <iostream>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	list<int>mylist1;
//	list<int>mylist2;
//
//	mylist1.push_back(2);
//	mylist1.push_back(5);
//	mylist1.push_back(20);
//	mylist2.push_back(1);
//	mylist2.push_back(4);
//	mylist2.push_back(5);
//
//	mylist2.merge(mylist1);
//
//	for(int a : mylist2)
//	{
//		cout<<a<<" ";
//	}
//	cout<<endl;
//
//	mylist2.push_back(0);
//
//	//sort(mylist2.begin(),mylist2.end());
//	mylist2.remove_if([](int x )
//	{
//		if(x == 5)
//			return true;
//		else
//			return false;
//	});
//
//	mylist2.sort();
//	for(int b: mylist2)
//	{
//		cout<<b<<" ";
//	}
//	cout<<endl;
//
//
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//struct node{
//	int data;
//	struct node *left;
//	struct node *right;
//};
//
//struct node* newNode(int val)
//{
//	struct node *tmp;
//	tmp = (struct node*)malloc(sizeof(struct node));
//	tmp->data = val;
//	tmp->left = NULL;
//	tmp->right = NULL;
//	return tmp;
//}
//
//struct node* insert(struct node *ptr,int num)
//{
//	if(!ptr)
//		ptr = newNode(num);
//	else if(ptr->data > num)
//		 ptr->left = insert(ptr->left,num);
//	else if(ptr->data < num)
//		 ptr->right = insert(ptr->right,num);
//	return ptr;
//
//
//}
//
//void InOrderTree(struct node* ptr)
//{
//	if(ptr == NULL)
//		return;
//
//	InOrderTree(ptr->left);
//	cout<<ptr->data<<" ";
//	InOrderTree(ptr->right);
//
//}
//
//
//void PreOrderTree(struct node* ptr)
//{
//	if(ptr == NULL)
//		return;
//
//	cout<<ptr->data<<" ";
//	PreOrderTree(ptr->left);
//	PreOrderTree(ptr->right);
//
//}
//
//
//int DistanceFromRoot(struct node *ptr,int x)
//{
//	if(ptr->data == x)
//		return 0;
//	else if(ptr->data > x)
//		return 1 + DistanceFromRoot(ptr->left , x);
//	return 1 + DistanceFromRoot(ptr->right ,x);
//
//}
//int DistanceBetweenTwoNodes(struct node *ptr,int a ,int b)
//{
//	if(ptr == NULL)
//		return 0;
//
//	if(ptr->data > a && ptr->data > b)
//		return DistanceBetweenTwoNodes(ptr->left,a,b);
//	else if(ptr->data < a && ptr->data < b)
//		return DistanceBetweenTwoNodes(ptr->right,a,b);
//	else if(ptr->data >= a && ptr->data <= b)
//		return DistanceFromRoot(ptr->left, a) +
//				DistanceFromRoot(ptr->right,b);
//}
//
//
//int main()
//{
//
//	struct node* root = NULL;
//    root = insert(root, 20);
//    insert(root, 10);
//    insert(root, 5);
//    insert(root, 15);
//    insert(root, 30);
//    insert(root, 25);
//    insert(root, 35);
//	cout<<"InOrderTree : ";
//	InOrderTree(root);
//	cout<<endl;
//
//	cout<<"PreOrderTree : ";
//	PreOrderTree(root);
//	cout<<endl;
//
//	cout<<"DistanceBetween(5,35) : ";
//	cout<<DistanceBetweenTwoNodes(root,5,35);
//	cout<<endl;
//	return 0;
//}




//#include <windows.h>
//#include <stdio.h>
//
//char* findNumber(int arr_count, int* arr, int k) {
//    bool bresult = false;
//
//    char *ptr  = (char *) malloc (10 * sizeof(char));
//    memset(ptr,0,(10 * sizeof(char)));
//
//    for(int i = 0;i<arr_count;i++)
//    {
//
//        if(arr[i] == k )
//            bresult = true;
//
//
//    }
//
//    if(bresult   == true)
//        strcpy(ptr,"YES");
//    else
//        strcpy(ptr,"NO");
//
//    return ptr;
//
//}
//
//int main()
//{
//
//	int arr[5] = {1,2,34,5,6};
//
//	char* res = findNumber(5,  arr, 67);
//
//    printf( "%s\n", res);
//	return 0;
//}


//#include <windows.h>
//#include <stdio.h>
//
////int *FindOddNums(int m,int n,int *arr)
////{
////  int cnt=0,flag = 0;
////
////  for(int i =m;i<n;i++)
////  {
////    for(int j = 2; j <= n/2; ++j)
////    {
////      // condition for nonprime number
////      if(m%j == 0)
////      {
////        flag = 1;
////        break;
////      }
////    }
////
////    if(flag == 0)
////      arr[cnt++] = m;
////  }
////
////  return arr;
////}
//int main()
//{
//
//	//int arr[10] = {0};
//
//	//FindOddNums(3,9,arr);
//
//	for(int i = 3;i<=9;i++)
//	{
//		if(i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//
//	}
//
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//int *arrReverse(int n,int *arr,int *res)
//{
//	res = &n;
//	int a[n];
//	for(int i = n-1;i>=0;i--)
//		arr[i] = arr[i];
//
//	return arr;
//}
//
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//
//	int res;
//
//	int *cnt = arrReverse(5,arr,&res);
//
//	for (int i = 0; i < res; i++)
//		cout<<*(cnt + i)<<" ";
//
//
//
//return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//
//int main()
//{
//
//	vector<int>vect;
//	int n = 4;
//
//	vect.push_back(1);
//	vect.push_back(2);
//	vect.push_back(3);
//	vect.push_back(4);
//	vect.push_back(5);
//
//	for(int b : vect)
//		cout<<b<<" ";
//
//	for(int i=0;i<n;i++)
//	{
//		int num = vect.at(0);
//
//		for(int i =0;i<vect.size();i++)
//		{
//			vect.at(i) = vect.at(i+1);
//		}
//
//		vect[vect.size()-1] = num;
//
//
//	}
//
//	for(int a : vect)
//		cout<<a<<" ";
//
//
//
//
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct node
//{
//	int data;
//	struct node *link;
//}*head = NULL;
//
//void CreateLL()
//{
//	struct node *current,*tmp;
//	int n,val;
//
//	cout<<"Enter no. of nodes : ";
//	cin>>n;
//	cout<<endl;
//	for(int i =0;i<n;i++)
//	{
//		cout<<"Enter data : ";
//		cin>>val;
//		cout<<endl;
//		tmp = (struct node *)malloc(sizeof(struct node));
//		tmp->data = val;
//		tmp->link = NULL;
//
//		if(head == NULL)
//		{
//			head = tmp;
//			current = tmp;
//
//		}
//		else
//		{
//			//while(current->link != NULL)
//				//current = current->link;
//			current->link = tmp;
//			current = tmp;
//
//		}
//	}
//}
//
//void DisplayLL()
//{
//	struct node *ptr;
//	if(head == NULL)
//		return;
//	ptr = head;
//	while(ptr!= NULL)
//	{
//		cout<<ptr->data<<"=>";
//		ptr = ptr->link;
//	}
//}
//
//void DeletKthNode(int k)
//{
//	if(head == NULL)
//		return;
//	struct node *ptr,*tmp;
//
//
//	if(head->data == k)
//	{
//		tmp = head;
//		head = head->link;
//		free(tmp);
//		return;
//	}
//	ptr = head;
//	while(ptr->link != NULL)
//	{
//		if(ptr->link->data == k)
//		{
//			tmp = ptr->link;
//			ptr->link = tmp->link;
//			free(tmp);
//
//		}
//		ptr = ptr->link;
//	}
//
//}
//
//
//void DeletLastNode()
//{
//	if(head == NULL)
//		return;
//
//	struct node *ptr,*tmp;
//
//	ptr = head;
//
//	while(ptr->link->link != NULL)
//		ptr = ptr->link;
//	ptr->link = NULL;
//
//
//
//
//
//}
//int main()
//{
//
//	cout<<"CreateLL :";
//	CreateLL();
//	cout<<endl;
//
//	cout<<"DisplayLL : ";
//	DisplayLL();
//	cout<<endl;
//
//
//	cout<<"DeletKthNode : ";
//	DeletKthNode(3);
//	DisplayLL();
//	cout<<endl;
//
//
//	cout<<"DeletLastNode : ";
//	DeletLastNode();
//	DisplayLL();
//	cout<<endl;
//
//
//
//
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Base
//{
//
//	int n;
//	static int a;
//	int *ptr;
//};
//
//int main()
//{
//	Base b;
//	cout<<"Size of Base : "<< sizeof(b)<<endl;
//	char str[100] = "I am Rohit";
//
//	char *token = strtok(str," ");
//	while(token != NULL)
//	{
//		cout<<token<<endl;
//		token = strtok(NULL," ");
//	}
//	return 0;
//}
//




//#include <iostream>
//
//using namespace std;
//
//class Derived;
//class Base
//{
//public:
//
//	virtual void Display()
//	{
//		cout << "Base : Display" << endl;
//	}
//
//	void Show()
//	{
//		cout << "Base : Show" << endl;
//	}
//};
//
//
//class Derived : public Base
//{
//
//public:
//	void Display()
//	{
//		cout << "Derived : Display" << endl;
//	}
//
//
//	void Show()
//	{
//		cout << "Derived : Show" << endl;
//	}
//
//
//};
//
//
//int main()
//{
//	Base* bPtr = new Derived();
//	bPtr->Display();
//	bPtr->Show();
//
//	return 0;
//}


//
//#include <windows.h>
//
//int main()
//{
//	HANDLE hMutex = INVALID_HANDLE_VALUE;
//	hMutex = CreateMutex(
//	           NULL,
//	           FALSE,
//	           L"MyMutex"
//	         );
//
//	if (hMutex == INVALID_HANDLE_VALUE)
//	{
//		::MessageBox(NULL, L"Invalid Mutex Handle", L"TRUE", MB_OK | MB_TOPMOST);
//	}
//
//
//
//
//
//	return 0;
//}



#include <iostream>

using namespace std;


int FindSecondMaxFromArray(int arr[], int len)
{
	int num1 = 0, num2 = 0;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] > num1)
		{
			num2 = num1;
			num1 = arr[i];

		}
		else if (arr[i] > num2)
		{
			num2 = arr[i];
		}
	}

	cout << "First largest no. is : " << num1 << endl;
	cout << "Second largest no. is : " << num2 << endl;

	return num2;
}

int main()
{
	int arr[] = {4, 98, 8, 6, 66, 74, 6, 8, 6, 5, 5, 7, 8, 9, 44, 8, 94, 55, 47, 8, 8, 9, 47};

	int n = sizeof(arr) / sizeof(arr[0]);

	FindSecondMaxFromArray(arr, n);


	return 0;
}