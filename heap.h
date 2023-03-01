#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	int m;
	PComparator c;

	std::vector<T> elements;

	bool isLeaf(int loc);

	//used to promote item to its proper location
	void trickleUp(int loc);

	//used with pop
	void trickleDown(int loc);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	this->m = m;
	this->c = c;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	return (elements.empty());
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return (elements.size());
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
	//recursive solution ?
	int parent = (loc-1)/m;

	//correct use of functor?
	//might be test error source
	while(parent >= 0 && c(elements[loc], elements[parent])){
		std::swap(elements[parent], elements[loc]);
		loc = parent;
		parent = (loc-1)/m;
	}
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::isLeaf(int loc){
	//I think I should only need to check if the LEFT node exists
	//that should identify that the node either is or is not a leaf.
	return ((loc*m) >= int((elements.size()-1)));
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc){
	//base
	if(isLeaf(loc)){return;}

	//initially left
	int smallerChild = ((loc*m)+1);
	if(smallerChild+1 < int(elements.size())){
			int rightChild = smallerChild+1;
			if(c(elements[rightChild], elements[smallerChild])){
					smallerChild = rightChild;
			}
	}
	//swap and move down
	if(c(elements[smallerChild], elements[loc])){
			std::swap(elements[loc], elements[smallerChild]);
			trickleDown(smallerChild);
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	elements.push_back(item);
	//send entry to correct spot to maintain heaps integrity
	trickleUp(elements.size()-1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw(std::underflow_error(""));
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return (elements[0]);

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw(std::underflow_error(""));
  }

	elements[0] = elements.back();
	elements.pop_back();
	if(empty()){
		return;
	}else{
		trickleDown(0);
	}
}



#endif