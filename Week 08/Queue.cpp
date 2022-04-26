class queue : private container
{
    private:
        int index;

    public:
        queue()
        {
            index = 0;
            box = new int[len];
        }
        queue(int l)
        {
            len = l;
            index = 0;
            box = new int[len];
        }
        queue(const queue &a)
        {
            this->len = a.len;
            box = new int[len];
            copy(a.box, box, len);
            index = a.index;
        }
        bool enqueue(int data)
        {
            if (len == index)
            {
                return false;
            }
            else
            {
                box[index++] = data;
                return true;
            }
        }
        int *dequeue()
        {
            if (index == 0 || box == NULL)
            {
                return NULL;
            }
            int *toBeReturn = new int;
            *toBeReturn = box[0];
            for (int i = 1; i < index; i++)
                box[i - 1] = box[i];
            index --;
            return toBeReturn;
        }
        bool increase() { return reallocate(len * 2); }
        int getLen() { return len; }
};
