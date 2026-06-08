# data-structureA 代码说明

本项目是 C++ 数据结构与算法练习集合。下面按目录列出每个文件的题目含义与算法核心。

## 根目录

- `README.md`: 项目源码索引。核心：按目录说明每个文件实现的题目和主要算法思路。

## chapter2

### chapter2/homework1

- `project1_1.cpp`: 两数之和。核心：双重循环枚举两个下标，找到和为目标值的一对元素。
- `project1_2.cpp`: 两数之和优化版。核心：用 `unordered_map` 保存"值 -> 下标"，遍历时查找 `target - nums[i]`。
- `project2.cpp`: 判断整数是否为回文数。核心：转字符串后用左右双指针比较。

### chapter2/homework2

- `project1.cpp`: 按 `K1`、`K2` 将顺序表划分为三段。核心：两次原地划分，先把 `< K1` 放左边，再把 `>= K2` 放右边。
- `project2.cpp`: 地址链表重排。核心：先用地址映射还原链表顺序，再用双指针从尾、头交替取节点输出新链表。
- `project3.cpp`: 判断两个字符串循环链表是否等价。核心：构造循环链表，从第二个链表每个可能起点尝试匹配一整圈。
- `project4.cpp`: 后缀表达式求值。核心：遇数入栈，遇运算符弹出两个操作数计算；早期版本只适合单字符数字。
- `project4_2.cpp`: 后缀表达式求值增强版。核心：按逗号分隔 token，支持多位数和负数，每行独立用栈求值。

### chapter2/segment1

- `SqList.h`: 顺序表模板类。核心：动态数组存储，支持扩容、尾插、按下标插入、删除和遍历。
- `deleteX.cpp`: 删除顺序表中所有值为 `x` 的元素。核心：提供写指针压缩法和原地逐个删除法。
- `merge.cpp`: 合并两个有序顺序表。核心：双指针归并，把较小元素依次加入第三个顺序表。
- `move.cpp`: 以首元素为基准划分顺序表。核心：提供一次扫描交换法和左右指针对撞法。
- `main.cpp`: 顺序表功能测试。核心：测试删除指定值、基准划分、归并有序表。
- `run_test`: 编译生成的测试可执行文件，不是源码。

### chapter2/segment2

- `LinkList.h`: 单链表模板类。核心：带头结点，支持尾插、按位置插入、删除、遍历和求长度。
- `diverse.cpp`: 单链表按序号拆分。核心：遍历原链表，把奇数位和偶数位节点分别尾插到两个新链表。
- `merge.cpp`: 合并两个有序单链表。核心：双指针比较节点值，尾插到结果链表。

## chapter3

### chapter3/homework

- `project1.cpp`: 任务处理系统等待时间计算。核心：按到达时间稳定排序，再顺序模拟单处理器累计等待时间。
- `project1_2.cpp`: 任务处理系统等待时间计算的栈实现。核心：用栈按到达时间插入排序，再反转后模拟处理。
- `project2.cpp`: 多队列超市排队模拟。核心：每个收银台维护一个队列，处理 `ENTERS` 和 `LEAVES` 指令并输出最终队列。
- `project3.cpp`: 条件反转循环队列。核心：保留 `-1` 的原位置，把其他元素入循环队列后转入栈，实现非 `-1` 元素逆序输出。

### chapter3/segment1

- `stack.h`: 顺序栈模板类。核心：数组存储，支持扩容、入栈、出栈、取栈顶和判空。
- `linkstack.h`: 链栈模板类。核心：头插法维护栈顶，入栈插到头结点之后，出栈删除首元结点。
- `clinkstack.h`: 循环链栈模板类。核心：只用 `rear` 指针表示栈底，节点循环连接，栈顶在 `rear->next`。
- `opand.cpp`: 后缀表达式求值。核心：扫描表达式，数字入栈，运算符弹栈计算。
- `postexp.cpp`: 中缀表达式转后缀表达式。核心：用运算符栈处理优先级和括号。

### chapter3/segment2

- `queue.h`: 非循环顺序队列。核心：`front/rear` 指针线性移动，会出现假溢出。
- `Cqueue.h`: 循环顺序队列。核心：取模移动 `front/rear`，空出一个位置区分队空和队满。
- `Cqueue2.h`: 带计数的循环队列。核心：用 `count` 区分满队和空队，可以使用全部数组空间。
- `linkQueue.h`: 链式队列。核心：维护 `front/rear` 指针，特别处理只有一个节点时的出队。

## chapter4

### chapter4/homework

- 该目录当前没有源码文件。

### chapter4/segment

- `kmp.cpp`: KMP 字符串匹配。核心：构造 `next` 数组，匹配失败时按前缀信息跳转，输出所有匹配位置。

## chapter5

### chapter5/homework

- `practice1.cpp`: LeetCode 59 螺旋矩阵 II。核心：按上、右、下、左四个边界收缩填数。
- `practice2.cpp`: N 皇后方案计数。核心：回溯逐行放皇后，用列数组和两条对角线数组剪枝。
- `practice3.cpp`: 递归输出全排列。核心：固定当前位置，与后续元素交换并递归。

## chapter6

### chapter6/homework1

- `project1.cpp`: 按不同顺序输出树的叶子结点和层序结果。核心：括号表示法建树，分别 DFS 左到右、右到左收集叶子，并用队列做右优先层序遍历。
- `project2.cpp`: 判断完全二叉树。核心：括号表示法建树，层序遍历时一旦遇到空节点，后续不能再出现非空节点。

### chapter6/homework2

- `project1.cpp`: 括号表示法输入二叉树并输出前序、中序、后序遍历。核心：栈建树，前序递归，中序用标记栈，后序递归。
- `project2.cpp`: 由前序和中序构造二叉树并输出后序。核心：前序首元素定位根，在中序中切分左右子树递归构造。

### chapter6/homework3

- `project1.cpp`: 编码前缀问题。核心：用二叉 Trie 插入 0/1 编码，检测已有编码是否为当前前缀、当前是否为已有编码前缀或重复。
- `project2.cpp`: 哈夫曼编码代价 / WPL。核心：小根堆每次合并两个最小权值，累计合并代价。
- `project3.cpp`: 求二叉树中距离目标节点为 `k` 的节点。核心：层序字符串建树，找根到目标路径，再从目标及各祖先的另一侧子树按剩余距离收集节点。

### chapter6/segment/BinaryTree

- `buildTree.cpp`: 多种二叉树构造方法。核心：实现前序+中序、带空标记前序、后序+中序、括号表示法、根左右行输入、层序+中序建树。
- `calculate.cpp`: 二叉树基本计算。核心：括号表示法建树，提供查找节点、求高度和销毁二叉树。
- `preorder.cpp`: 二叉树前序遍历。核心：递归版、显式栈版、一路向左的非递归版。
- `inorder.cpp`: 二叉树中序遍历。核心：递归版、任务标记栈版、一路向左入栈版。
- `postorder.cpp`: 二叉树后序遍历。核心：递归版、双栈/反向思路版、标记栈版。
- `levelorder.cpp`: 二叉树层序遍历。核心：队列 BFS，包含普通序列输出和按层分组输出。

### chapter6/segment/ThreadBinaryTree

- `inorder.cpp`: 中序线索二叉树。核心：递归线索化，把空左/右指针改为前驱/后继，再无栈中序遍历。
- `preorder.cpp`: 先序线索二叉树。核心：按根左右顺序建立线索，遍历时优先走左孩子，否则沿右线索/右孩子前进。
- `postorder.cpp`: 后序线索二叉树。核心：按左右根顺序建立后序线索，重点维护共享的前驱指针。

## chapter7

### chapter7/segment

- `graph.cpp`: 图的两种存储结构。核心：邻接矩阵直接二维数组存储；邻接表通过头结点 + 边结点链表存储，构造时从后向前头插以保证遍历顺序与邻接矩阵一致。
- `bfs.cpp`: 邻接表的广度优先遍历。核心：用队列层层扩展，节点入队即刻标记已访问，避免重复入队。
- `dfs.cpp`: 邻接表的深度优先遍历。核心：递归版直接按邻接表深入；非递归版用栈模拟，找到一个未访问邻接点就 `break` 深入，没有可走的邻接点才出栈回溯。
- `mst.cpp`: 最小生成树。核心：Prim 算法用 `lowcost[]` 记录非树点到树的最小权、`closest[]` 记录对应树内端点，每轮选最小后用新加入点松弛；Kruskal 算法把所有边按权升序排序，用并查集思想的 `vset[]` 特征位判同集合，不同集合就并入。
- `shortestPath.cpp`: 最短路径。核心：Dijkstra 单源算法用 `S[]` 标记已确定点，每轮在未确定点中挑 `dist` 最小者加入并松弛邻居；Floyd 多源算法三重循环以中间点 `k` 不断更新 `A[i][j]`，`path[i][j]` 存放路径中 `j` 的前驱以便逆向回溯输出整条路径。

### chapter7/homework

- `project1.cpp`: 邻接矩阵 + BFS 判断两点之间是否连通。核心：起点入队后做广度优先搜索，到达终点立即返回 `true`。
- `project2.cpp`: 邻接矩阵 + DFS 输出遍历序列。核心：分别用递归 DFS 和栈式非递归 DFS 输出从指定起点出发的两种遍历结果。

### chapter7/homework2

- `project1.cpp`: 网络延迟时间。核心：以 `K` 为源点跑 Dijkstra 求所有点的最短到达时间，结果取 `dist[]` 中的最大值；如果有点不可达就返回 `-1`。输入直接"用节点值当下标"建邻接矩阵，没有边的位置必须置为 `INF`。
- `project2.cpp`: Floyd 算法求无向图最小环。核心：在用 `k` 松弛之前，先枚举 `i, j < k`，把"`i→...→j`（仅经过编号 `<k` 的中间点的最短路）+ 原边 `g[j][k]` + 原边 `g[k][i]`"作为经过 `k` 的环长度候选，再做常规 Floyd 更新。重边只保留最小的一条。
- `project3.cpp`: 信息传播 / 经纪人问题。核心：Floyd 求任意两点最短路后，枚举每个起点 `i`，看是否能传到所有人；可达时取 `max(dist[i][j])` 作为这个人的最差传播时间，挑全员可达且最差时间最小的人输出。

## chapter8

### chapter8/segment

- `find.cpp`: 折半查找。核心：迭代版用 `low/high` 不断缩半，相等返回 `mid`、小走左、大走右；递归版用辅助函数 `BinSearch21(R, low, high, k)` 处理同样的三种分支。
- `BST.cpp`: 二叉排序树类模板 `BSTClass<T1,T2>`。核心：插入递归 `_InsertBST` 按 `k < key / k > key` 走左右子树，等键修改 `data`；`CreateBST` 用第一个元素建根、其余调用 `InsertBST`；查找 `_SearchBST` 递归向左右下行；`r` 是根、`f` 临时记录待删节点的双亲。
- `AVL.cpp`: AVL 平衡二叉树类模板。核心：每个节点存子树高度 `ht`，提供四种旋转 —— LL 直接右旋；RR 直接左旋；LR 先对左孩子左旋再对自己右旋；RL 先对右孩子右旋再对自己左旋。旋转后必须先更新原根再更新新根的 `ht`。
- `total.cpp`: AVL 树完整实现（插入 + 删除 + 自动平衡）。核心：每个节点维护 `height`，提供通用 `balance(root)` 函数 —— 先 `updateHeight` 再算平衡因子 `bf`，`bf > 1` 时根据左孩子的平衡因子判定 LL 还是 LR，`bf < -1` 时判定 RR 还是 RL；插入和删除递归回溯时都 `return balance(root)`，所以删除可以从下往上多次自动调整。一句话：`AVL = BST + 高度维护 + 平衡因子判断 + 旋转`。

### chapter8/homework1

- `project1.cpp`: 折半查找并输出查找经过的元素序列。核心：每次进入循环先把 `R[mid]` 推入 `ans`（必须放在 `return` 前面），找到返回 `mid`、否则按大小调整 `low/high`。文件 IO：从 `in.txt` 读目标值和有序序列，结果写 `out.txt`。
- `project2.cpp`: 判断完全二叉树（数组式输入，`"null"` 表空）是否为平衡二叉树。核心：用 `checkHeight` 返回子树高度，左右子树有任一为 `-1` 或高度差 `> 1` 时直接返回 `-1` 作为"不平衡"哨兵，避免重复遍历。
- `project3.cpp`: 求 `n` 个数两两差值绝对值的中位数（二分答案 + 双指针）。核心：排序后对"差值上限 `mid`"二分，用双指针滑动窗口在 `O(n)` 内统计差值 `<= mid` 的对数；目标位次取 `(C(n,2) + 1) / 2`，用 `long long` 防溢出。

### chapter8/homework2

- `project1.cpp`: 二叉排序树（BST）插入与删除。核心：递归插入 `insertNode` 用"`root->left = insertNode(root->left, x)`"把新叶子挂回父节点；删除分四种情况——叶子直接 `delete`；只有一侧子树时用子树替代当前结点；左右子树都有时找**左子树最大值**（一路向右）覆盖当前结点 `data`，再递归到左子树删那个最大结点。
- `project2.cpp`: 拉链法哈希表 + 平均查找长度。核心：取 `M = 13` 保证样例无冲突，哈希函数 `key % M`，每个桶用头插法挂链；统计 ASL 时遍历每个桶累加位置 `1, 2, 3, ...`，最后除以元素总数（向下取整）。
- `project3.cpp`: 在 BST 中查找第一个大于 `k` 的节点值。核心：层序序列建树（`-1` 表示空），查找时若当前结点 `> k` 则记录并继续向左找更小的候选，否则向右；最终返回大于 `k` 的最小值，不存在返回 `-1`。

## daily-practice1

- `project01.cpp`: 中缀表达式转后缀表达式。核心：运算符栈处理优先级、括号和多位数字输出。
- `project02.cpp`: 只用一个辅助栈完成栈排序。核心：从原栈取元素，借助辅助栈保持有序，不合适的元素临时倒回原栈。
- `project03.cpp`: 用两个栈实现队列。核心：入队进输入栈，出队/取队头时必要时倒入输出栈。
- `project04.cpp`: 用队列实现栈。核心：入栈后旋转队列，使新元素始终位于队头。
- `project05.cpp`: 顺序栈基本操作。核心：数组实现入栈、出栈、判空、取栈顶。
- `project06.cpp`: 循环队列基本操作。核心：数组取模维护 `front/rear`，处理入队、出队和查询。
- `project07.cpp`: 空文件，当前未实现。
- `project08.cpp`: 链栈基本操作。核心：链表头部作为栈顶，实现入栈、出栈和取栈顶。
- `project09.cpp`: 括号匹配。核心：左括号入栈，右括号检查栈顶类型并弹出，最后栈空则匹配。
- `project10.cpp`: 后缀表达式求值。核心：数字入栈，运算符弹出两个数计算后再入栈。
- `project14.cpp`: 判断链表是否有环。核心：用数组模拟静态链表的 `next`，快慢指针判环。
- `project15.cpp`: 合并两个有序链表。核心：双指针比较节点值，复用/连接较小节点。
- `project16.cpp`: 链表去重。核心：遍历有序链表，删除相邻重复节点。
- `project17.cpp`: 链表奇偶位分离。核心：把奇数位节点和偶数位节点拆成两条链，再拼接。
- `project18.cpp`: 单链表迭代逆置。核心：三指针逐个反转 `next` 指向。
- `project19.cpp`: 顺序表去重。核心：保持相对顺序，扫描时只写入第一次出现的元素。
- `project20.cpp`: 顺序表逆置。核心：左右双指针交换元素。
- `project21.cpp`: 有序顺序表合并。核心：双指针归并两个有序数组。
- `project23.cpp`: 单链表递归逆置。核心：递归反转后半段，回溯时让后继节点指回当前节点。
- `project24.cpp`: 单链表基本操作。核心：带头结点实现创建、插入、删除、遍历。
- `project25.cpp`: 查找倒数第 `k` 个节点。核心：快慢指针保持 `k` 个间距，一次遍历定位。
- `project25_2.cpp`: 查找倒数第 `k` 个节点改进版。核心：同样使用快慢指针，一次遍历输出目标节点。
- `test1.cpp`: 带权重的括号深度计算。核心：自定义栈检查括号匹配，并按嵌套深度累计权重。

## daily-practice2

- `project01.cpp`: 判断二叉树是否轴对称。核心：按带 `-1` 空节点的前序序列建树，递归比较左右子树镜像位置。
- `project02.cpp`: 二叉树镜像翻转。核心：递归交换每个节点的左右子树，再输出先序遍历。
- `project03.cpp`: 计算二叉树高度。核心：提供递归求左右子树最大高度和 BFS 层序计高两种思路。
- `project04.cpp`: 二叉树序列化和反序列化。核心：带空节点标记的前序建树，再输出前序/中序等结果。
- `project05.cpp`: 判断两棵二叉树是否相同。核心：同步递归比较节点是否同时为空、值是否相同、左右子树是否相同。
- `project06.cpp`: 求二叉树叶子节点个数。核心：递归统计左右子树叶子数，空树返回 0，叶子返回 1。
- `project07.cpp`: 求二叉树节点总数。核心：递归统计 `1 + 左子树节点数 + 右子树节点数`。
- `project14.cpp`: 表达式树求值。核心：按 `id type value left right` 建树，用 `flag` 排除所有被当作孩子的节点后剩下的就是根；`evaluate` 是后序思想——先递归求左右子树的值，再按当前运算符合并。
- `project15.cpp`: BST 转有序双向链表。核心：先序序列（`-1` 表空）建树，中序遍历过程中用引用参数 `head/prev` 把节点依次串起来，`left` 当前驱、`right` 当后继；`prev == NULL` 时记录链表头。
- `project16.cpp`: 二叉排序树插入 / 查找 / 删除 / 求最值。核心：递归插入用 `root->left = insertVal(root->left, x)` 把新叶子挂回父节点；删除分四种情况，左右子树都有时用**左子树最大值（中序前驱）**覆盖当前值再递归删除那个前驱。
- `project17.cpp`: 判断是否为二叉排序树。核心：中序遍历配合引用参数 `prev`，一旦发现 `prev->val >= root->val`（不严格递增）立即返回 `false`。

## lab1

- `project1.cpp`: 解码形如 `3[a2[c]]` 的压缩字符串。核心：两个栈分别保存重复次数和上一层字符串，遇 `]` 后展开拼接。
- `project2.cpp`: 反转链表指定区间。核心：定位区间前驱和右端节点，三指针反转 `[left, right]` 后接回原链表。
- `project3.cpp`: 串的模式匹配计数。核心：KMP 构造 `next` 数组，统计模式串在主串中出现次数。
- `project4.cpp`: 日志错误类型定位。核心：KMP 查找模式串在日志串中的所有出现位置，输出最后一次出现的 1 基位置。

## lab2

- `project1.cpp`: 约瑟夫环（循环单链表实现）。核心：维护 `head/tail`，每轮从当前节点出发移动 `m-1` 次定位出列者，删除时同步更新 `head/tail`。
- `project2.cpp`: 括号表示法（含负数）建树，输出从右到左的叶子节点和中序遍历序列。核心：栈记录父节点和左右子树标志位 `k`，中序用一路向左的非递归遍历。
- `project3.cpp`: 判断括号表示二叉树中两个字符是否在同一层，并输出它们子树中除自身以外的叶子。核心：层序遍历找同层并记录两节点，再分别对两节点的左右子树递归收集叶子。

## practice

- `project1.cpp`: 后序遍历输出叶子节点。核心：按 `父 左 右` 行输入（`#` 表空）用 `map<char, Node*>` 建树，后序递归到底，左右孩子都为空才输出。
- `project2.cpp`: 输出二叉树的边界（左边界 + 叶子 + 右边界）。核心：左边界从根**有左走左、没左走右**地下沉，右边界对称且最后倒序，叶子单独 DFS 收集；用 `existsInAns` 去重避免拐角节点被重复计入。
- `project2_2.cpp`: `project2` 的精简版（多位数当字符串、`map` 建树）。核心：同样是左边界（有左走左没左走右）、中间叶子、右边界倒序三段拼接；关键提醒——**左边界不是只走左边**，且叶子统一交给中间一段处理以防重复。

## weeklyTest

### weeklyTest/week1

- `project1.cpp`: 求链表 `A - B`。核心：遍历 B 中每个值，在 A 中用前驱指针删除所有相同节点。
- `project2.cpp`: 递增链表去重。核心：因为链表有序，只需删除相邻重复节点。
- `project3.cpp`: 找出两个有序链表合并后的第 `k` 小值。核心：双指针模拟归并，只计数到第 `k` 个。

### weeklyTest/week2

- `project1.cpp`: 列车编组，使奇数在偶数前面。核心：用栈分别组织奇数和偶数序列，再按要求输出。
- `project2.cpp`: 利用顺序栈倒置循环队列元素。核心：循环队列全部出队压栈，再弹栈入队实现逆序。
- `project3.cpp`: 杨辉三角。核心：二维数组/向量递推，边界为 1，中间为上一行相邻两数之和。

### weeklyTest/week3

- `project1.cpp`: 主对角线元素求和。核心：读入矩阵并累计 `i == j` 的元素。
- `project2.cpp`: 判断链串是否对称。核心：链式存储字符串，用首尾比较或栈/递归思想检查回文。
- `project3.cpp`: 递归删除链表节点。核心：先递归处理后续节点，回溯时删除值等于目标的当前节点。

### weeklyTest/week4

- `project1.cpp`: 输出二叉树每个节点的层次（先序输出）。核心：按"A B C"行输入（`#` 表示空孩子）用 `map` 索引节点建树；先 BFS 标层再先序输出，也可在先序递归时把 `level` 直接作为参数下传。
- `project2.cpp`: 统计完全二叉树（顺序串表示，`#` 为空）中的单分支节点个数。核心：按下标 `2i+1`、`2i+2` 递归建树，DFS 中判断"恰好一个孩子为空"则计数。
- `project3.cpp`: 由层次序列 + 中序序列构造二叉树并输出先序。核心：层序首元素是根，用中序划分左右子树，再用左右子树的集合从层序中筛出左右子树的层序，递归构造。

---

## 重点内容

下面汇总了散落在各个源码注释中、自己写代码时反复踩坑或反复提醒自己的关键点，按主题归类。

### 一、顺序表 / 数组

- **扩容时不要重复定义变量**（`chapter2/segment1/SqList.h`）：`T* data = new T[newCapacity];` 会在函数内定义局部变量 `data`，覆盖类成员，导致后续访问的还是旧数组。
- **以首元素为基准划分顺序表**（`chapter2/segment1/move.cpp`）：
  - 单指针交换法：循环必须从 `j = 1` 开始，否则会直接换掉基准值本身。
  - 左右指针对撞法：必须先从右往左找 `<= pivot` 的元素，再从左往右找 `> pivot` 的元素，否则收尾交换时基准会落到错误的位置。
- **原地删除所有值为 `x` 的元素**（`chapter2/segment1/deleteX.cpp`）：删除后不能直接 `i++`，因为后面顶上来的元素可能仍是 `x`，会漏判；只有当前元素不是 `x` 时才 `i++`。
- **顺序表去重保持相对顺序**（`daily-practice1/project19.cpp`）：用 `unordered_map` 记录是否首次出现，只在第一次出现时写入。

### 二、链表

- **求长度时遍历条件**（`chapter2/segment2/LinkList.h`）：`while(p != NULL)` 而不是 `while(p->next != NULL)`，否则最后一个节点会被漏数。
- **正序插入 / 删除一定要从头节点出发**（`daily-practice1/project24.cpp`）：因为需要前驱节点，从 `head->next` 出发就找不到第一个元素的前驱。
- **`getline` + `stringstream` 解析的字符串记得去掉 `\r`**（`daily-practice1/project24.cpp` 等多处）：Windows 换行会让 `input[0]` 变成 `"CREATE\r"`，匹配不上任何条件。
- **迭代逆置**（`daily-practice1/project18.cpp`）：使用快慢两指针（前一个、当前），先把慢指针指向 `NULL`，再依次反转，注意"先暂存后继再断链"。
- **递归逆置**（`daily-practice1/project23.cpp`）：`curr` 是 `head->next`，进入函数先判空；递归到尾节点返回作为 `newHead`，回溯时执行 `curr->next->next = curr; curr->next = NULL;`。
- **快慢指针找倒数第 `k` 个节点**（`daily-practice1/project25_2.cpp`）：让 `fast` 先走 `k` 步，注意循环中**不要忘了 `count++`**，否则会变成死循环。
- **链表去重时不要乱动前驱指针**（`weeklyTest/week1/project2.cpp`）：发现重复时只删除后继节点，`curr` 仍要做前驱继续比较新的 `curr->next`，不能直接前移。
- **链表奇偶位分离**（`daily-practice1/project17.cpp`）：循环条件 `curr2 != NULL && curr2->next != NULL` 必须把 `curr2 != NULL` 放前面，否则会出现 `NULL->next` 段错误。
- **循环链表的析构要先断环**（`chapter2/homework2/project3.cpp`）：找到尾结点把 `next` 置为 `NULL`，再按普通链表释放，否则会无限循环。
- **约瑟夫环**（`lab2/project1.cpp`）：不要在"位置"上做文章，统一按"从当前节点移动 `m-1` 次"理解；每次删除节点都要同步检查并更新 `head` 和 `tail`。

### 三、栈 / 队列 / 表达式

- **链栈 push 用头插**（`chapter3/segment1/linkstack.h`）：`s->next = head->next; head->next = s;`，head 之后的节点即栈顶。
- **循环链栈无哨兵节点**（`chapter3/segment1/clinkstack.h`）：构造时 `rear = NULL` 而不是 `new Node()`；`pop` 时若只剩一个元素必须把 `rear` 置为 `NULL`，否则后续判断失效。
- **非循环顺序队列的 `gethead`**（`chapter3/segment2/queue.h`）：`front` 是头节点之前的哨兵位置，除了 `pop` 操作不能随便移动。
- **链式队列只有一个元素出队**（`chapter3/segment2/linkQueue.h`）：必须把 `front` 和 `rear` 同时重置为 `NULL`。
- **后缀表达式求值要支持多位数**（`chapter3/segment1/opand.cpp`、`daily-practice1/project10.cpp`）：扫描到数字后要内层循环把整串数字读完再 `stoi`；判断条件用 `isdigit` 时注意它判的是字符而不是字符串。
- **中缀转后缀别忘了收尾**（`chapter3/segment1/postexp.cpp`）：扫描完成后还要把运算符栈里剩下的全部弹出追加到结果末尾。
- **栈排序辅助栈**（`daily-practice1/project02.cpp`）：访问 `st.top()` 前**一定**要判断非空，否则会运行时崩溃。
- **用栈实现队列**（`daily-practice1/project03.cpp`）：`getline + stringstream` 切 token 时，`token` 必须声明成 `string` 而不是 `char`。
- **带权重的括号深度**（`daily-practice1/test1.cpp`）：循环结束后栈不空说明有多余的左括号未匹配，要补一个最终校验。
- **任务排序模拟**（`chapter3/homework/project1.cpp`）：用 `Box b(arr, exe); tasks.push_back(b);` 直接构造对象，`new Box` 返回的是指针类型，不能直接放进 `vector<Box>`。
- **`cin >> n` 之后接 `getline` 必须 `cin.ignore()`**（`chapter2/homework2/project2.cpp` 等）：吞掉残留的换行符，否则首个 `getline` 会读到空串。

### 四、字符串匹配（KMP）

- **匹配主循环必须处理 `j == -1`**（`chapter4/segment/kmp.cpp`、`lab1/project4.cpp`）：判断条件写成 `if (j == -1 || s[i] == t[j])`，否则当模式串第一个字符失配时无法重新从头开始匹配。
- **匹配成功的下标是 `i - m`**（或 1 基位置 `i - m + 1`），命中后用 `j = next[j]` 继续找重叠匹配。

### 五、二叉树

- **判断轴对称的递归边界**（`daily-practice2/project01.cpp`）：先写"两个都为 NULL 返回 true"，再写"其中一个为 NULL 或值不同返回 false"，顺序不能反。
- **括号表示法建树**（多处）：栈保存父节点，`k = 1` 表示接下来是左子树，`k = 2` 是右子树，遇 `(` 推父 / 遇 `)` 弹父；解析数字要单独处理负号和多位数。
- **多种建树方式按行输入用 `map` 索引**（`chapter6/segment/BinaryTree/buildTree.cpp`、`weeklyTest/week4/project1.cpp`）：**需要按值反复访问之前的节点，就用 `map<char, Node*>`**；第一行的左字符就是根。
- **层序 + 中序建树**（`weeklyTest/week4/project3.cpp`、`buildTree.cpp` 的 `buildTree`）：层序首元素是根，用中序切左右，再用左右子树的字符集合从层序里"过滤"出左右子树的层序——因为层序的左右子树是混在一起的，不能直接切。
- **后序 + 中序建树时区间不要算错**（`buildTree.cpp` 的 `helper3`）：左子树后序区间 `[postStart, postStart + leftSize - 1]`，右子树后序区间 `[postStart + leftSize, postEnd - 1]`。
- **层序遍历（队列 BFS）**（`chapter6/segment/BinaryTree/levelorder.cpp`）：左孩子先入队、右孩子后入队；按层分组就用 `int levelSize = q.size();` 把当前层一次性处理完。
- **层序"从右向左"**（`chapter6/homework1/project1.cpp`）：先 push 右孩子，再 push 左孩子。
- **二叉树前序遍历（非递归）**（`chapter6/segment/BinaryTree/preorder.cpp`）：
  - 版本 1（显式栈）：先压右孩子再压左孩子；
  - 版本 2（一路向左）：进入时直接输出，向左下沉并入栈，到底后弹栈转向右子树。
- **二叉树中序遍历（非递归）**（`chapter6/segment/BinaryTree/inorder.cpp`）：
  - 任务标记栈版：先压右、再压"根（已标记 true）"、再压左；
  - 一路向左版：一路压左到底，弹栈输出后转向右子树。
- **先序线索二叉树致命点**（`chapter6/segment/ThreadBinaryTree/preorder.cpp`）：递归前必须判 `p->ltag == 0`，否则刚把左线索指向 `pre` 后，递归 `p->lchild` 会无限回头爆栈；遍历结束记得把最后一个节点 `rtag` 置 1。`pre` 必须用**指针的引用**传递。
- **二叉树两节点的同层判断 + 输出兄弟侧的叶子**（`lab2/project3.cpp`）：不处理"目标节点本身可能是叶子"的方法是**分别对它的左子树和右子树递归收集叶子**，这样自动跳过节点自身。
- **空指针保护**（`lab2/project2.cpp`）：递归可以让函数自己处理空；但只要要访问空指针的成员，或者把它放进队列后还要再访问，就必须先判空。

### 六、图

- **邻接表构造时倒序遍历**（`chapter7/segment/graph.cpp`、`bfs.cpp`、`dfs.cpp`）：构造邻接表用头插法，内层循环要 `for (int j = n - 1; j >= 0; j--)`，这样链表顺序才与邻接矩阵从左到右一致。

### 七、BFS 与 DFS 核心模板

#### 1. BFS 广度优先遍历

用的是：

```
queue<int> q;
```

核心思想：**一层一层访问**。

模板：

```
queue<int> q;
visited[start] = 1;
q.push(start);

while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (u的每个邻接点v) {
        if (v没有访问过) {
            visited[v] = 1;
            q.push(v);
        }
    }
}
```

最关键的一点是：**一个点一旦入队，就应该立刻标记为已访问。**
不是等它出队的时候才标记。否则同一个点可能被多个点重复加入队列。

#### 2. DFS 递归核心模板

```
void DFS(int u) {
    visited[u] = 1;
    cout << u << " ";

    for (u的每个邻接点v) {
        if (visited[v] == 0) {
            DFS(v);
        }
    }
}
```

最关键的一点是：**访问一个点时，立刻标记为已访问。**
也就是：

```
visited[u] = 1;
```

要放在进入这个点的时候。

#### 3. DFS 非递归核心模板

推荐这个版本，因为它最接近递归 DFS：

```
stack<int> st;

visited[start] = 1;
cout << start << " ";
st.push(start);

while (!st.empty()) {
    int u = st.top();

    bool found = false;

    for (u的每个邻接点v) {
        if (visited[v] == 0) {
            visited[v] = 1;
            cout << v << " ";
            st.push(v);

            found = true;
            break;
        }
    }

    if (!found) {
        st.pop();
    }
}
```

最关键的一点是：**DFS 是一条路走到底，走不下去才回退。**
所以非递归里面：

```
break;
```

不是退出整个 DFS，而是表示：
我已经找到一个没访问过的邻接点了，现在要先深入它，其他邻接点以后再说。

#### 4. BFS 与 DFS 对比记忆

| 维度 | BFS | DFS |
| --- | --- | --- |
| 容器 | `queue<int> q;` | 递归用系统栈；非递归用 `stack<int> st;` |
| 思想 | 一层一层访问 | 一条路走到底，走不下去再回退 |
| 标记时机 | **入队**时立刻标记 | **入栈 / 进入节点**时立刻标记 |
| 关键点 | 同一节点不允许被多个邻居重复入队 | 找到一个未访问邻接点就 `break` 深入；当前点无路可走才 `st.pop()` 回溯 |

### 八、最小生成树与最短路径

- **Prim 的 `lowcost[k] = 0` 是"已加入树"的标记**（`chapter7/segment/mst.cpp`）：每轮先扫描 `lowcost[j] != 0` 找最小，选中后把 `lowcost[k]` 置 0，再用 `g.edges[k][j] < lowcost[j]` 做松弛——**松弛只需要看新加入的 k，不要从头遍历整张邻接矩阵。**
- **Kruskal 的并集合并**（`chapter7/segment/mst.cpp`）：取边 `(u,v)` 时比较 `vset[u]` 和 `vset[v]` 两个特征位，不同才接收；合并时必须把所有等于 `sn2` 的特征位整体改成 `sn1`，否则后续判断会失效。
- **Dijkstra 初始化**（`chapter7/segment/shortestPath.cpp`、`chapter7/homework2/project1.cpp`）：`dist[i] = edges[v][i]`，`v` 到 `i` 有边时 `path[i] = v`，否则 `path[i] = -1`；源点直接 `S[v] = 1`。这样松弛循环 `g.n - 1` 次而不是 `g.n` 次。
- **Dijkstra 没有边的位置必须显式置 `INF`**（`chapter7/homework2/project1.cpp`）：松弛条件 `g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]` 依赖这个约定，否则一个 `0` 邻接矩阵会被当成"边权为 0 的捷径"。
- **Floyd 路径回溯**（`chapter7/segment/shortestPath.cpp`）：`path[i][j]` 保存"`i` 到 `j` 最短路径上 `j` 的前驱"，松弛时写 `path[i][j] = path[k][j]`（不是 `k`）；输出时从终点 `j` 反向走 `pre = path[i][pre]`，到 `i` 停止再反向打印。
- **Floyd 求最小环**（`chapter7/homework2/project2.cpp`）：核心是利用 `dista[i][j]` 在引入 `k` 之前只用了编号 `<k` 的中间点，所以 `dista[i][j] + g[i][k] + g[k][j]` 构成一个不重复经过 `k` 的环；枚举必须放在用 `k` 更新 `dista` 之前。`i < j < k` 是为了避免重复计数同一个环。

### 九、查找

- **折半查找区间收敛**（`chapter8/segment/find.cpp`、`chapter8/homework1/project1.cpp`）：循环条件用 `low <= high`（带等号），收缩时 `high = mid - 1` / `low = mid + 1`；不能写成 `high = mid` / `low = mid`，否则在剩两个元素时可能死循环。
- **要"输出查找路径"时，`R[mid]` 必须在判断之前 push**（`chapter8/homework1/project1.cpp`）：放在 `return` 后面会漏掉命中元素本身。
- **二分答案 + 双指针计对数**（`chapter8/homework1/project3.cpp`）：先排序，外层二分 `mid`（差值上限），内层用 `right` 扫描时让 `left` 一起右移到 `arr[right] - arr[left] <= mid`，每个 `right` 贡献 `right - left` 对。
- **中位数的目标位次**（`chapter8/homework1/project3.cpp`）：总对数 `n*(n-1)/2`，目标位次为 `(total + 1) / 2`；用 `long long` 算，`n*(n-1)` 容易溢出。
- **BST 插入返回根**（`chapter8/segment/BST.cpp`）：`_InsertBST` 的递归签名是返回 `BSTNode*` 并在调用点 `p->lchild = _InsertBST(p->lchild, ...)`，这样新建的叶子能"挂回"父亲；不能写成 void 修改。

### 十、AVL 树（旋转 / 插入 / 删除）

#### 1. 四种旋转的对应关系（`chapter8/segment/AVL.cpp`、`chapter8/segment/total.cpp`）

- **LL 型**（左孩子的左子树过高）→ 对失衡结点**右旋**；
- **RR 型**（右孩子的右子树过高）→ 对失衡结点**左旋**；
- **LR 型**（左孩子的右子树过高）→ 先对**左孩子左旋**，再对失衡结点**右旋**；
- **RL 型**（右孩子的左子树过高）→ 先对**右孩子右旋**，再对失衡结点**左旋**。

**理解**：LL 是左边过长所以需要右旋，把左孩子顶上来；RR 同理。LR 是"根节点左边过长，根节点的左孩子右边过长"——必须**从下到上分析**，先让 `root->left` 左旋把它"扳成 LL 型"，再让 `root` 右旋；RL 同理（先让 `root->right` 右旋，再让 `root` 左旋）。

#### 2. BST 删除（左右子树都有的情况）

不是简单"交换两个结点"，准确做法是：**用左子树最大值覆盖当前结点的 `data`，然后递归到左子树删除那个最大结点**（一路向右就能找到左子树最大值）。也可以对称地用右子树最小值替代——两者效果相同。

#### 3. 检查平衡的实现（`chapter8/segment/total.cpp`）

`AVL = BST + 高度维护 + 平衡因子判断 + 旋转`。插入/删除都是先按普通 BST 操作，递归回溯时再从下往上检查每个祖先的平衡。

```
Node* balance(Node* root) {
    if (root == NULL) return NULL;

    updateHeight(root);                 // 先按子树高度更新自己
    int bf = getBalance(root);          // 平衡因子 = 左高 - 右高

    if (bf > 1) {                       // 左边过高
        if (getBalance(root->left) >= 0)
            return rightRotate(root);   // LL
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);   // LR
        }
    }

    if (bf < -1) {                      // 右边过高
        if (getBalance(root->right) <= 0)
            return leftRotate(root);    // RR
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);    // RL
        }
    }

    return root;                        // 没失衡，原样返回
}
```

插入和删除都在递归末尾 `return balance(root);`，等于每一层都检查一次当前结点是否失衡。

#### 4. 其他易错点

- **旋转后 `ht` 更新顺序**（`chapter8/segment/AVL.cpp`）：先更新原根 `a`，再更新新根 `b`。因为 `b` 的子树包含 `a`，`a` 的新高度算完之后 `b` 才能正确 `max(getht(left), getht(right)) + 1`。
- **新建叶子 `ht = 1`**：AVL 的高度按"包含自己"的层数算，叶子是 1 不是 0，`getht(NULL)` 才返回 0。
- **插入 vs 删除**：插入失衡通常调整一次就够；删除失衡可能从删除点一路向上多次调整。但因为代码是递归写的，每一层都 `return balance(root);`，删除也能自动一路向上检查。

### 十一、B 树 / B+ 树

#### 1. m 阶 B 树定义

- 每个结点至多有 m 棵子树（至多 m-1 个关键字）；
- 根结点若不是叶子，至少有 2 棵子树；
- 除根结点外，所有结点至少有 `ceil(m/2)` 棵子树，即至少含 `ceil(m/2) - 1` 个关键字；
- 所有叶子结点在同一层。

**结点结构**：一个有 `n` 个关键字的结点，有 `n + 1` 个指针（子树）：

```
n  p0  key1  p1  key2  p2  ...  keyn  pn
```

**高度**：B 树高度 `h` **不含外部结点层**，外部结点层看作第 `h + 1` 层。

#### 2. 外部失败结点

- "外部结点" / "外部失败结点" 不是 B 树的真实结点，不存关键字。它是把所有"查找失败时落到的空指针位置"补出来形成的一层，用来分析失败查找。
- B 树的**叶子结点是真实结点**，里面可以存关键字。**到达叶子结点 ≠ 查找失败**；只有在叶子里没找到、并且要继续往下却没有真实孩子时，才落到外部失败结点。
- 直观理解：若关键字集合为 `10, 20, 30`，则查找失败的位置有 4 个区间 `<10 / 10~20 / 20~30 / >30`，每个区间对应一个外部失败结点。

#### 3. 关键字数 vs 外部结点数（B 树）

| 公式 | 结论 |
| --- | --- |
| 关系 | **外部结点数 = 关键字总数 + 1** |
| 最少外部结点数（高度 h 的 m 阶 B 树） | `2 × ceil(m/2)^(h-1)` |
| 最多外部结点数 | `m^h` |
| 最少关键字数 | 外部结点数 - 1 |
| 最多关键字数 | `m^h - 1` |

**计数模板（高度 h 的 m 阶 B 树最少关键字数）**：

```
第1层（根）          : 1 个结点，1 个关键字
第2层               : ≥2 个结点（根至少 2 孩子）
第3层 ~ 第h层       : 每个非根结点至少 ceil(m/2) 孩子，
                     每个结点至少 ceil(m/2)-1 个关键字
```

**例题1**：高度为 3 的 5 阶 B 树（不含外部结点），关键字数最少 = `1 + 2×2 + 6×2 = 17`，最多 = `(1+5+25)×4 = 124`。
**例题2**：高度为 5 的 3 阶 B 树，最少外部结点数 = `2 × 2^4 = 32`，最少关键字数 = `32 - 1 = 31`。

#### 4. m 阶 B+ 树

- 所有**叶子结点**包含全部关键字以及指向数据记录的指针；叶子结点按关键字大小顺序**链接**。
- 分支结点（非叶子）只起索引作用，仅包含各子树中**最大（或最小）**关键字。
- **B+ 树中有 n 棵子树的结点有 n 个关键字**（不同于 B 树的 n 棵子树对应 n-1 个关键字）。
- B+ 树常考的是"叶子结点数 / 数据元素数"，不要硬套 B 树的 `外部结点数 = 关键字数 + 1`。

#### 5. B 树 vs B+ 树对比

| 维度 | B 树 | B+ 树 |
| --- | --- | --- |
| 关键字存放位置 | 所有结点都可存数据 | **只在叶子结点存数据**，分支结点只做索引 |
| n 棵子树对应关键字数 | n - 1 | n |
| 查找路径 | 命中即返回，路径长度不定 | 一定要走到叶子才能取到数据 |
| 区间查询 | 较慢 | 叶子层是有序链表，**遍历方便** |
| 典型应用 | 内存索引、文件系统 | 数据库 B+ 索引（如 MySQL InnoDB） |

### 十二、哈希表

- **拉链法（链地址法）实现**（`chapter8/homework2/project2.cpp`）：表本身是一个指针数组，每个槽位指向一条链表。`hash(key) = key % M` 决定关键字落到哪条链；插入用头插法 `newNode->next = table[index]; table[index] = newNode;`。
- **ASL 怎么算**：每个关键字单独算自己被查到时需要的比较次数，再求平均。同一条链里，链头那个比较 1 次，第二个 2 次，第三个 3 次……与"头插还是尾插"无关，**累计和都一样**，所以平均成功查找长度也一样。
- **计数器每次都从 1 重置**：每一次查找都是一次独立过程，从链表头开始重新数。不是"查完第一个再查第二个时累加"。
- **线性探测法**（开放地址法）：冲突后用 `Hi = (H(key) + i) % m` 向后探测，`i = 0, 1, 2, ...`。简单但容易产生"堆积"（聚集）现象。若 `n` 个关键字互为同义词，依次插入需要的探测次数为 `1 + 2 + ... + n = n(n+1)/2`。
- **折半查找失败的比较次数**：长度为 `n` 的有序表上，最多比较 `⌈log2(n+1)⌉` 次。例如 `n = 16` 时最多 5 次。

### 十三、`!!!` 标注速查

- **BST 删除"只有右子树"分支的判断**（`chapter8/homework2/project1.cpp`）：写成 `else if (root->left == NULL)`，判断条件是 `== NULL` 不是 `!= NULL`。容易写反——思维上是"只有右子树"，但代码里检查的是"左子树是空的"。
- **AVL 的核心心法**（`chapter8/segment/total.cpp`）：`AVL < BST < 普通二叉排序树`（约束越来越强）；不管是插入还是删除，都是先在普通 BST 上完成操作，**回溯时检查平衡 → 旋转**（AVL 专有），整套逻辑通过 `return balance(root);` 一行串起来。

### 十四、递归理解（链表 / 二叉树 / 图）

递归看着千变万化，但**按"函数到底返回什么、要不要返回"来分类**，就只有下面 6 种。读代码时先问自己：*这个递归函数的一句话语义是什么？* 想清楚这句话，递归就不难了。

#### 1. 遍历型递归

- **目标**：按某种顺序访问每个节点，**不一定需要返回值**，重点是访问顺序。
- **常见形式**：前序（根左右）、中序（左根右）、后序（左右根）；图里就是 DFS。
- **本项目用到的文件**：
  - `chapter6/segment/BinaryTree/preorder.cpp`、`inorder.cpp`、`postorder.cpp`（三种遍历的递归版）
  - `chapter6/segment/ThreadBinaryTree/inorder.cpp`、`preorder.cpp`、`postorder.cpp`（递归线索化本质也是按序遍历）
  - `chapter6/homework2/project1.cpp`（前序、后序递归输出）
  - `practice/project1.cpp`（后序遍历，只在叶子处输出）
  - `chapter7/segment/dfs.cpp`、`chapter7/homework1/project2.cpp`、`chapter7/homework2/project2.cpp`（图的 DFS 递归遍历）

```
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val;        // 中序：左 → 根 → 右
    inorder(root->right);
}
```

#### 2. 构造型递归

- **目标**：创建结构并**返回创建好的根节点**——返回值不是用来判断真假，而是用来"接结构"。
- **一句话语义**：`buildTree()` = 读一段序列，建一棵树，返回这棵树的根。
- **关键三句**：`root->left = buildTree(); root->right = buildTree(); return root;`——左右子树让递归去建，最后把当前根交还给上一层。
- **本项目用到的文件**：
  - `daily-practice2/project15.cpp`、`project17.cpp`（先序 `-1` 表空建树）
  - `daily-practice2/project01.cpp`、`project04.cpp`（带空标记前序建树）
  - `chapter6/segment/BinaryTree/buildTree.cpp`（前序+中序、后序+中序、层序+中序等多种构造）
  - `chapter6/homework2/project2.cpp`（前序+中序构造）
  - `weeklyTest/week4/project2.cpp`、`project3.cpp`
  - 插入也是构造型：`chapter8/segment/BST.cpp` 的 `_InsertBST`、`chapter8/homework2/project1.cpp`、`daily-practice2/project16.cpp` 的 `insertVal`（`root->left = insertVal(root->left, x)` 把新叶子挂回父节点）

```
Node* buildTree() {
    int x; cin >> x;
    if (x == -1) return NULL;          // 空树
    Node* root = new Node(x);
    root->left  = buildTree();         // 左子树让递归建
    root->right = buildTree();         // 右子树让递归建
    return root;                       // 把当前根交还上一层
}
```

#### 3. 判断型递归

- **目标**：判断是否满足某个条件，返回 `bool`。
- **模板感很强**：`if (空) return true; if (左不满足) return false; if (当前不满足) return false; if (右不满足) return false; return true;`——发现一个错就立刻 `return false`，全对才 `return true`。
- **本项目用到的文件**：
  - `daily-practice2/project17.cpp`（判断 BST，中序配合 `prev`）
  - `daily-practice2/project01.cpp`（判断轴对称，左右镜像比较）
  - `daily-practice2/project05.cpp`（判断两棵树是否相同）
  - `chapter8/homework1/project2.cpp`（判断平衡二叉树，用 `-1` 作"不平衡"哨兵）
  - 查找也算判断型：`daily-practice2/project16.cpp` 的 `find`、`chapter8/segment/BST.cpp` 的 `_SearchBST`、`weeklyTest/week3/project2.cpp`（链串回文）

```
bool isBST(Node* root, Node*& prev) {
    if (root == NULL) return true;
    if (!isBST(root->left, prev)) return false;          // 左边不满足
    if (prev != NULL && prev->val >= root->val) return false; // 当前不满足
    prev = root;
    if (!isBST(root->right, prev)) return false;         // 右边不满足
    return true;
}
```

#### 4. 计算型递归

- **目标**：从子问题得到结果，**合并**成当前结果——本质就是**后序思想（左 → 右 → 根）**。
- **本项目用到的文件**：
  - `daily-practice2/project14.cpp`（表达式树求值：先算左右子树值，再按运算符合并）
  - `daily-practice2/project03.cpp`（树高）、`project06.cpp`（叶子个数）、`project07.cpp`（节点总数）
  - `chapter6/segment/BinaryTree/calculate.cpp`（求高度）
  - `chapter8/homework1/project2.cpp` 的 `checkHeight`（既算高度又顺带判平衡）

```
int evaluate(Node* root) {
    if (root->type == 0) return stoi(root->value);   // 叶子是数字
    int l = evaluate(root->left);                    // 先拿左结果
    int r = evaluate(root->right);                   // 再拿右结果
    if (root->value == "+") return l + r;            // 最后合并
    if (root->value == "-") return l - r;
    if (root->value == "*") return l * r;
    if (root->value == "/") return l / r;
    return 0;
}
```

#### 5. 修改状态型递归

- **目标**：递归本身不返回主要结果，结果通过**引用参数 / 全局变量 / vector** 等外部状态保存。
- **本项目用到的文件**：
  - `daily-practice2/project15.cpp`（BST 转双向链表，用 `head/prev` 引用边中序边串链）
  - `daily-practice2/project17.cpp`（判 BST 时维护中序前驱 `prev`——既判断又改状态）
  - `practice/project2.cpp`、`practice/project2_2.cpp`、`lab2/project3.cpp`、`chapter6/homework1/project1.cpp`（递归把叶子收进 `vector& ans`）
  - `chapter6/homework3/project3.cpp`（按剩余距离收集节点）
  - `weeklyTest/week4/project1.cpp`（先序递归时把 `level` 作为参数下传）

```
void collectLeaves(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) { ans.push_back(root->val); return; }
    collectLeaves(root->left, ans);
    collectLeaves(root->right, ans);
}
```

#### 6. 修改结构型递归

- **目标**：在**递归返回（回溯）过程中修改原有结构的指针关系**——先递归到底，回溯时改指针。
- **本项目用到的文件**：
  - `daily-practice1/project23.cpp`（链表递归逆置）
  - `daily-practice2/project02.cpp`（二叉树镜像翻转，递归交换左右孩子）
  - `weeklyTest/week3/project3.cpp`（递归删除链表节点，回溯时删）
  - `daily-practice2/project16.cpp` 的 `deleteVal`（BST 删除，回溯时重接子树）

以**链表递归逆置**为例（`daily-practice1/project23.cpp`）：

```
Node* reverse(Node* curr) {
    if (curr == NULL || curr->next == NULL) return curr;  // 递归到尾节点，它就是新头
    Node* newHead = reverse(curr->next);                  // 先一路深入到尾部
    curr->next->next = curr;                              // 回溯时让后继指回自己
    curr->next = NULL;                                    // 断开原来的正向指针
    return newHead;                                       // 新头一路返回到最外层
}
```

对 `1 → 2 → 3` 的过程：递归深入到 `3` 返回作为 `newHead`；回到 `2` 时 `3->next = 2`、`2->next = NULL`，得到 `3 → 2`；回到 `1` 时 `2->next = 1`、`1->next = NULL`，最终 `3 → 2 → 1`。**特点：先递归到尾部，回溯时改指针，最后返回新头。**

#### 7. 用 `buildTree()` 彻底吃透"构造型递归"

构造型是最容易绕晕的，关键是记住：**每一层递归都有自己独立的 `root`，名字相同但不是同一个变量。**

代码（`daily-practice2/project15.cpp`、`project17.cpp`）：

```
Node* buildTree() {
    int x;
    if (!(cin >> x)) return NULL;
    if (x == -1) return NULL;
    Node* root = new Node(x);
    root->left  = buildTree();
    root->right = buildTree();
    return root;
}
```

设输入 `4 2 1 -1 -1 3 -1 -1 5 -1 -1`，对应树：

```
    4
   / \
  2   5
 / \
1   3
```

执行顺序（把每层的 `root` 想成 `root_4 / root_2 / root_1`，互不干扰）：

1. 读 `4` → `new Node(4)`，然后**暂停**去建左子树（还没轮到 `root->right`）。
2. 读 `2` → `new Node(2)`，再去建 `2` 的左子树。
3. 读 `1` → `new Node(1)`；它的左右都读到 `-1`，于是 `1->left = 1->right = NULL`，`return` 节点 `1`。这个返回值被上一层接住：`2->left = 1`。
4. 回到 `2` 这层执行 `root->right = buildTree()`，读 `3`，建好后 `return`，于是 `2->right = 3`；`2` 左右都好了，`return` 节点 `2`，被最外层接住：`4->left = 2`。
5. 回到 `4` 这层执行 `root->right = buildTree()`，读 `5`（左右都是 `-1`），`return`，于是 `4->right = 5`。
6. 最外层 `return root` 返回的就是整棵树的根 `4`，`main` 里的 `root = buildTree()` 拿到的正是它。

**一句话总结**：`root->left = buildTree();` 的含义就是"请递归帮我建好左子树，并把左子树的根返回给我接住"；右子树同理。子树建好就把根返回给父节点，父节点用 `left/right` 接住，最外层最后返回整棵树的根。

> 备注：图的 BFS / DFS 遍历模板（队列、栈、标记时机）见上文 **七、BFS 与 DFS 核心模板**，这里不再重复。