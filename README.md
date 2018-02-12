# 数据结构-链表
## 单链表Slink
- 支持从小到大,从大到小的整数排序
- 链表头不存东西,从小到大的链表头是INT_MIN,从大到小是INT_MAX
### API
- 数组转链表
pNODE generaterList(int * arr, int size, WAYS methods)

- 返回大小接口
int getSize(pNODE list)

- 打印链表接口
void getPrint(pNODE root)

- 返回指定节点接口
int getItem(pNODE root, int index)

- 删除指定节点接口
int deleteItem(pNODE root, int index)

- 删除整个列表
void deleteList(pNODE root)

## 双链表Dlink
- 从小到大排序

### API

数组转链表

pNode generaterDList(int * arr,int size)

返回大小接口

int getSizeDList(pNode list)

打印链表接口

void getPrintDList(pNode root)

返回指定节点接口

int getItemDList(pNode root, int index)

插入值到链表

pNode insertItemDList(pNode root, int index)

删除指定节点接口

int deleteItemDList(pNode root, int index)

删除指定值接口

int deleteValueDList(pNode root, int index)

删除整个链表
void deleteListDList(pNode *root)



### 测试用例
见main函数