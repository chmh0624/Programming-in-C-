/*
  class container
  {
  protected:
      int *box;
      int len;
      void copy(int *from, int *to, int l)
      {
          for (int i = 0; i < l; i++)
              to[i] = from[i];
      }

  public:
      container() : box(NULL), len(1) {}
      container(int l)
      {
          int *tmp = new int[l];
          this->len = l;
          this->box = tmp;
      }
      container(const container &a)
      {
          int *tmp = new int[a.len];
          copy(a.box, tmp, a.len);
          this->len = a.len;
      }
      int getLen() const
      {
          return this->len;
      }
      virtual bool put_in(int obj) = 0;
      virtual int *take_out(void) = 0;
  };
*/

class queue: public container
{
    public:
        int idx = 0;
        bool put_in(int obj)
        {
            if (idx == len)
                return false;
            box[idx++] = obj;
            return true;
        }

        int *take_out()
        {
            if (idx == 0)
                return NULL;
            int *ptr = new int;
            *ptr = box[0];
            for (int i=0; i<idx-1; i++)
                box[i] = box[i+1];
            idx --;
            return ptr;
        }
};

class priority_queue: public queue
{
    public:
        bool order;
        priority_queue(int _len, bool f)
        {
            len = _len;
            order = f;
            idx = 0;
            box = new int[len];
        }
        int *take_out()
        {
            if (idx == 0 || box == NULL) return NULL;
            int min = box[0], max = box[0], minidx = 0, maxidx = 0;
            for (int i=0; i<idx; i++)
            {
                if (box[i] < min)
                {
                    min = box[i];
                    minidx = i;
                }
                if (box[i] > max)
                {
                    max = box[i];
                    maxidx = i;
                }
            }
            int *ptr = new int;
            if (order)
            {
                for (int i=maxidx; i<idx-1; i++)
                    box[i] = box[i+1];
                idx --;
                *ptr = max;
            }
            else
            {
                for (int i=minidx; i<idx-1; i++)
                    box[i] = box[i+1];
                idx --;
                *ptr = min;
            }
            return ptr;
        }
};
