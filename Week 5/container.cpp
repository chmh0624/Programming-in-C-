class container
{
private:
  int *box, len, index;
  static int count;
  static void increase() { count ++; }
  static void decrease() { count --; }
  bool reallocate(int size) 
  {
    if (size == 0) size ++;
    
    int *newBox = new int[size];
    if (newBox == NULL) 
        return false;
    for (int i=0; i<=index; i++)
        newBox[i] = box[i];
    delete [] box;
    box = newBox;
    len = size;
    return true;
  }
public:
  container(void): box(NULL), len(0), index(-1) { increase(); }
  container (int _len) { box = new int[_len]; increase(); index = -1;}
  ~container () { delete [] box; decrease(); }
  int getLen() { return len; }
  int getIndex() { return index; }
  static int getCount() { return count; }
  void traversal()
  {
    if (index == -1) 
        std::cout << "empty";
    else
    {
        for (int i=0; i<=index; i++) 
            std::cout << box[i] << " ";
    }
    std::cout << "\n";
  }
  bool push(int data)
  {
    if (index == len - 1)
    {
        if (reallocate(len * 2))
        {
            box[++index] = data;
            return true;
        }
        return false;
    }
    else
    {
        box[++index] = data;
        return true;
    }
  }
  int pop()
  {
    if (index == -1)
        return 0;
    else
    {
        int head = box[0];
        for (int i=1; i<=index; i++)
            box[i-1] = box[i];
        index --;
        return head;
    }
  }
};

int container::count = 0;
