#ifndef NODE_H
#define NODE_H

template <typename itemType>
class Node {
private:
  itemType m_entry;
  Node<itemType>* m_left = nullptr;
  Node<itemType>* m_right = nullptr;

public:
  Node(){};
  Node(itemType entry) : m_entry(entry){}

  void setLeft(Node<itemType>* ptr){m_left = ptr;}

  Node<itemType>* getLeft(){return m_left;}

  void setRight(Node<itemType>* ptr){m_right = ptr;}

  Node<itemType>* getRight(){return m_right;}

  void setEntry(itemType& entry){m_entry = entry;}

  itemType getEntry()const{return m_entry;}

};

#endif
