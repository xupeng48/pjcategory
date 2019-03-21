## QTSkeleton

QTSkeleton是通过内容预占位方式向用户展示正在发生的事情，相比菊花loading而言可以更直观的让用户了解到他们正在等待的内容。

实现原理主要是对UIView进行拓展，添加属性containerView，表示占位视图的容器视图，其中每个占位区域都是一个view。对于想要显示占位效果的view，需实现协议，在协议方法中返回view列表。将这些view添加到containerView并显示。

参考链接 `https://github.com/OpenFeyn/Somo`
在这个基础上进行了简单优化，比如tableview代理的自动切换，collectionview的支持，蜻蜓的默认skeletonView等


## 安装

```
// tag替换为最新的
pod 'QTSkeleton', :git => "git@git2.qingtingfm.com:CocoaPods/qtskeleton.git", :tag => '0.1.0'
```

## 使用

### QTSkeleton基础使用

1.遵守协议`<QTSkeletonProtocol>`，并实现协议方法。
```
@required
- (NSArray<UIView *> *)skeletonSubViews;

@optional
- (UIColor *)skeletonContainerViewColor;
```
2.内容加载时对遵守协议的View，执行`- (void)skeletonStart;`方法。

3.内容加载完成时执行`- (void)skeletonStop;`方法。

### QTSkeleton支持UITableView和UICollectionView
1.`UITableViewCell`可继承`QTSkeletonTableViewCell`，`QTSkeletonTableViewCell`实现了`<QTSkeletonProtocol>`协议并有默认实现，如有特殊要求或者不符合设计，可重写进行修改或不继承`QTSkeletonTableViewCell`自己来实现协议。

2.`UITableView`创建后需要交给`QTSkeletonTableViewAgent`持有。`UITableView`的`numberOfSections`和`numberOfRowsInSection` ，默认分别为1和20。
```
self.tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
[self.tableView registerClass:[QTDemoTableViewCell class] forCellReuseIdentifier:NSStringFromClass([QTDemoTableViewCell class])];
self.agent = [[QTSkeletonTableViewAgent alloc] initWithHolder:self tableView:self.tableView rowHeight:120];
```

*`QTSkeletonTableViewAgent`根据`NSIndexPath`初始化
```
self.agent = [[QTSkeletonTableViewAgent alloc] initWithHolder:self
                                                    tableView:self.tableView
                                           tableViewCellBlock:^UITableViewCell<QTSkeletonProtocol> *(UITableView *tableView, NSIndexPath *indexPath) {
                                               return [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([QTDemoTableViewCell class]) forIndexPath:indexPath];
                                           } heightBlock:^CGFloat(UITableView *tableView, NSIndexPath *indexPath) {
                                               return 120;
                                           }];
```
*另外可以设置`UITableView`的`numberOfSections`、`numberOfRowsInSection`、`UITableViewCell`、`UITableViewHeaderView`、`UITableViewFooterView`信息。 
```
- (instancetype)initWithHolder:(id)holder
                     tableView:(UITableView *)tableView
              numberOfSections:(NSInteger)numberOfSections
         numberOfRowsInSection:(QTSkeletonNumberOfRowsInSectionBlock)numberOfRowsInSectionBlock
            tableViewCellBlock:(QTSkeletonTableViewCellBlock)cellBlock
                   heightBlock:(QTSkeletonTableViewCellHeightBlock)cellHeightBlock
               headerViewBlock:(QTSkeletonTableViewHeaderViewBlock)headerViewBlock
         headerViewHeightBlock:(QTSkeletonTableViewHeaderViewHeightBlock)headerViewHeightBlock
               footerViewBlock:(QTSkeletonTableViewFooterViewBlock)footerViewBlock
         footerViewHeightBlock:(QTSkeletonTableViewFooterViewHeightBlock)footerViewHeightBlock;
```


3.当网络请求数据返回后，对`QTSkeletonTableViewAgent`执行`reload`操作。
```
[self.agent reload];
```

4.`- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;`中执行`- (void)skeletonStop;`方法。
```
#pragma mark -- 在这里必调用 skeletonStop
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    [cell skeletonStop];
}
```
