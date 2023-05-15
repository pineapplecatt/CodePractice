#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sort {
   public:
    // 冒泡排序
    /*
    数据基本有序或数据较少（约15）时使用
     */
    template <typename T>
    void BubbleSort(vector<T>& arr) {
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            // 比较已排序元素
            for (int j = 0; j < len - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // 快速排序
    /*
    T最优：每次基准总在最中间（O(nlog2n)）;最坏：数据已有序（O(n^2)）。
    即key越靠近中央，左右子序列长度越接近，排序速度越快；越无序越快
    S：需要栈空间实现递归。最坏：S(n)=O(n);一般：S(n)=O(log2n)
    优化：随机选择key或左中右三元素的中位数作为key
    */
    template <typename T>
    void QuickSort(vector<T>& arr, int low, int high) {
        // 错误输入或只有一个元素
        if (low >= high) {
            return;
        }
        T key = arr[low];  // 设为基准值
        int i = low;
        int j = high;
        while (i != j) {
            // 从右向左找第一个小于k的数
            while (i < j && arr[j] >= key) {
                j--;
            }
            // 从左向右找第一个大于等于k的数
            while (i < j && arr[i] <= key) {
                i++;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        // 将key放到最终位置
        swap(arr[low], arr[i]);

        // 递归调用
        QuickSort(arr, low, i - 1);
        QuickSort(arr, i + 1, high);
    }

    // 直接插入排序
    /*
    最坏：数据递减序O(n^2)；最好：数据递增序O(n)，趟数固定n-1，不等于T
    用于小规模数据或基本有序数据时高效
    */
    template <typename T>
    void InsertionSort1(vector<T>& arr) {
        int len = arr.size();
        int i, j;
        T temp;
        // 认为首元素已有序
        for (i = 1; i < len; i++) {
            if (arr[i] < arr[i - 1]) {
                temp = arr[i];
                // 在已排序序列中向前扫描
                for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                    arr[j + 1] = arr[j];  // arr[j]右移
                }
                // temp放到最终位置
                arr[j + 1] = temp;
            }
        }
    }
    template <typename T>
    void InsertionSort2(vector<T>& arr) {
        int len = arr.size();
        // 认为首元素已有序
        for (int i = 1; i < len; i++) {
            // 在已排序序列中向前扫描
            for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
                swap(arr[j], arr[j + 1]);  // arr[j]右移
            }
        }
    }

    // 折半插入排序
    template <typename T>
    void BinaryInsertionSort(vector<T>& arr) {
        int len = arr.size();
        // 认为首元素已有序
        for (int i = 1; i < len; i++) {
            int low = 0;
            int high = i - 1;
            int mid;
            // 折半查找插入位置
            while (high >= low) {
                mid = (low + high) / 2;
                if (arr[mid] > arr[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // 在已排序序列中向前扫描
            for (int j = i - 1; j > high; j--) {
                swap(arr[j], arr[j + 1]);  // arr[j]右移
            }
        }
    }

    // 希尔排序
    /*
    按照增量距离分组，每次对每组进行插入排序，小元素大体在前，大元素大体在后，增量为1时数组已接近有序
    各组进行插入时并非先对一个组排序完再排序另一个组，而是轮流对每个组进行插入排序
    在插入排序时是跳跃性插入，可能破坏稳定性
    复杂度与增量序列（{1,2,4,8,...}）相关，普通最坏情况为O(n^2)，有很多改进，略
    */
    template <typename T>
    void ShellSort(vector<T>& arr) {
        int len = arr.size();
        // 设置增量为数组长度一半，逐步缩小为一半，最终为1
        for (int step = len / 2; step > 0; step /= 2) {
            // 插入排序
            for (int i = step; i < len; i++) {
                // 组内元素两两相隔step
                for (int j = i - step; j >= 0 && arr[j] > arr[j + 1]; j -= step) {
                    swap(arr[j], arr[j + step]);
                }
            }
        }
    }

    // 选择排序
    // 共n-1趟
    template <typename T>
    void SelectionSort(vector<T>& arr) {
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            int min = i;
            // 在未排序区寻找最小元素
            for (int j = i + 1; j < len; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            // 放入已排序区末尾
            swap(arr[min], arr[i]);
        }
    }

    // 堆排序
    /*
    最坏复杂度为O(nlogn)，不适合记录较少的排序
    */
    // 构建大根堆
    template <typename T>
    void Heapify(vector<T>& arr, int len, int dad) {
        // 待建堆数组，待建长度，待建父节点
        int largest = dad;
        int lson = dad * 2 + 1;  // 左孩子索引
        int rson = dad * 2 + 2;  // 右孩子索引
        // 找到根、左、右最大值并与根交换
        if (lson < len && arr[largest] < arr[lson]) {
            largest = lson;
        }
        if (rson < len && arr[largest] < arr[rson]) {
            largest = rson;
        }
        if (largest != dad) {
            swap(arr[largest], arr[dad]);
            Heapify(arr, len, largest);
        }
    }

    template <typename T>
    void HeapSort(vector<T>& arr) {
        int len = arr.size();
        // 从最后一个非叶节点开始建堆
        for (int i = len / 2 - 1; i >= 0; i--) {
            Heapify(arr, len, i);
        }
        // 将堆顶元素放到排序最终位置
        for (int i = len - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            Heapify(arr, i, 0);  // 剩余元素建堆
        }
    }

    // 归并排序
    template <typename T>
    void Merge(vector<T>& arr, int begin, int mid, int end) {
        int len1 = mid - begin + 1;
        int len2 = end - mid;
        // 创建临时数组用于存储原数组
        vector<T> L(len1);
        vector<T> R(len2);
        for (int i = 0; i < len1; i++) {
            L[i] = arr[begin + i];
        }
        for (int j = 0; j < len2; j++) {
            R[j] = arr[mid + 1 + j];
        }
        int i = 0;      // 初始化左临时数组索引
        int j = 0;      // 初始化右临时数组索引
        int k = begin;  // 初始化原数组索引
        // 合并临时数组
        while (i < len1 && j < len2) {
            /*if (L[i] <= R[j]) {
                arr[k] = L[i++];
            } else {
                arr[k] = R[j++];
            }
            k++;*/
            arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
        }
        // 处理临时数组剩余元素
        while (i < len1) {
            arr[k++] = L[i++];
        }
        while (j < len2) {
            arr[k++] = R[j++];
        }
    }

    // 递归版
    template <typename T>
    void MergeSort1(vector<T>& arr, int begin, int end) {
        if (begin < end) {
            int mid = begin + ((end - begin) >> 1);
            // int mid = begin + (end - begin) / 2;
            //  递归排序左右部分
            MergeSort(arr, begin, mid);
            MergeSort(arr, mid + 1, end);
            // 合并左右部分
            Merge(arr, begin, mid, end);
        }
    }

    // 迭代版
    template <typename T>
    void MergeSort2(vector<T>& arr) {
        int len = arr.size();
        vector<T> temp(len);
        int curSize;  // 当前合并的子数组大小，从1到n/2
        int start;    // 当前合并的子数组起点
        for (curSize = 1; curSize < len; curSize *= 2) {
            for (start = 0; start < len; start += 2 * curSize) {
                // Merge(arr, low, mid, end);
                int low = start;
                int mid = min(start + curSize - 1, len - 1);
                int high = min(start + 2 * curSize - 1, len - 1);
                // 模拟左右临时数组
                int begin1 = low, end1 = mid;
                int begin2 = mid + 1, end2 = high;
                while (begin1 <= end1 && begin2 <= end2) {
                    temp[low++] = arr[begin1] < arr[begin2] ? arr[begin1++] : arr[begin2++];
                }
                while (begin1 <= end1) {
                    temp[low++] = arr[begin1++];
                }
                while (begin2 <= end2) {
                    temp[low++] = arr[begin2++];
                }
            }
            // 把临时数组的值赋给arr
            arr.swap(temp);
        }
    }

    // 计数排序
    /*
    适合最大值不大的情况，如果元素个数少但最大值很大，会造成空间浪费
    作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是非负整数。实现逻辑如下：
    ① 找出待排序的数组中最大和最小的元素
    ② 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
    ③ 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
    ④ 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
    */
    void CountingSort(vector<int>& arr) {
        int len = arr.size();
        // 元素至少两个
        if (len <= 1) {
            return;
        }
        // 记录arr最大元素作为count数组最大下标
        int maxVal = arr[0];
        for (auto x : arr) {
            if (maxVal < x) {
                maxVal = x;
            }
        }
        vector<int> count(maxVal + 1, 0);
        vector<int> temp(arr);
        // 统计arr每个元素出现次数，存入count
        for (auto x : arr) {
            count[x]++;
        }
        // 对每个元素x，计算<=x的元素个数
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i - 1];
        }
        // 反向填充arr
        for (int i = len - 1; i >= 0; i--) {
            // temp[i]表示原来排序位置，因为从1开始所以再-1
            arr[count[temp[i]] - 1] = temp[i];
            count[temp[i]]--;  // temp[i]个数-1
        }
    }

    // 桶排序
    // 未完成
    void BucketSort(vector<int>& arr) {
        int len = arr.size();
        // 元素至少两个
        if (len <= 1) {
            return;
        }
        // 记录arr最大元素作为count数组最大下标
        int maxVal = arr[0];
        for (auto x : arr) {
            if (maxVal < x) {
                maxVal = x;
            }
        }
        const int bucketCnt = 10;
        vector<int> buckets(bucketCnt);
    }

    // 基数排序
    /*
    以空间换时间，占用内存很大
    当对海量数据排序时，容易造成 OutOfMemoryError
    只能排序非负数，负数需要添加绝对值并反转
    */
    void RadixSort(vector<int>& arr) {
        int len = arr.size();
        // 元素至少两个
        if (len <= 1) {
            return;
        }
        // 记录arr最大元素作为count数组最大下标
        int maxVal = arr[0];
        for (auto x : arr) {
            if (maxVal < x) {
                maxVal = x;
            }
        }
        // 计算最大元素位数
        int maxLen = to_string(maxVal).size();
        // 10个桶，0~9，每个桶大小为len
        vector<vector<int>> bucket(10, vector<int>(len));
        // 记录每个桶中存放了多少数据
        vector<int> bucketNums(10);
        // 循环maxLen次，每次用digit记录各元素的n位(个十百千...)
        for (int i = 0, n = 1; i < maxLen; i++, n *= 10) {
            for (int j = 0; j < len; j++) {
                int digit = arr[j] / n % 10;
                // arr[j]放入本次循环位的数对应的桶中，记录数量自增
                bucket[digit][bucketNums[digit]++] = arr[j];
            }
            int index = 0;  // 所取元素需要放的位置
            // 取出各个桶中数据，并将数据记录置0（桶本身数据还在）
            for (int i = 0; i < bucketNums.size(); i++) {
                if (bucketNums[i] != 0) {
                    for (int j = 0; j < bucketNums[i]; j++) {
                        arr[index++] = bucket[i][j];
                    }
                    bucketNums[i] = 0;
                }
            }
        }
    }
};

int main() {
    Sort s;
    vector<int> t{3, 5, 0, 6, 2, 4, 3, 1, 8, 5, 3, 2, 8, 4, 7, 9};
    // vector<int> t{5, 1, 4, 2, 8, 4};
    int l = t.size() - 1;
    s.RadixSort(t);
    for (auto x : t) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
