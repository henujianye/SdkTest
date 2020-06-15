//
//  MiGuAreaMusicObjects.h
//  MiGuAreaMusicSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#pragma mark -- 数据对象定义
//标签信息
@interface TagInfo : NSObject
//标签ID
@property (nonatomic,copy) NSString *tagId;
//标签名称
@property (nonatomic,copy) NSString *tagName;
//备注
@property (nonatomic,copy) NSString *remark;
//排序位置
@property (nonatomic,assign) int priority;
@end

//标签库信息
@interface GroupInfo : NSObject
//标签库ID
@property (nonatomic,copy) NSString *groupId;
//标签库名称
@property (nonatomic,copy) NSString *groupName;
//标签集合
@property (nonatomic, copy) NSMutableArray *tagInfos;
@end

//音乐信息
@interface MusicInfo : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
//歌曲名称
@property (nonatomic,copy) NSString *musicName;
//歌手名
@property (nonatomic,copy) NSString *singerName;
//图片地址
@property (nonatomic,copy) NSString *picUrl;
//歌曲试听地址
@property (nonatomic,copy) NSString *listenUrl;
//试听地址【高清格式】歌曲id查询歌曲信息接口才返回
@property (nonatomic,copy) NSString *hqListenUrl;
//试听地址【无损格式】歌曲id查询歌曲信息接口才返回
@property (nonatomic,copy) NSString *sqListenUrl;
//歌词地址
@property (nonatomic,copy) NSString *lrcUrl;
//是否已收藏
@property (nonatomic,assign) BOOL isCollection;
//歌曲bpm
@property (nonatomic,assign) int bpm;
//是否CP授权,1已授权/0未授权，SDK只能播放已授权的歌曲
@property (nonatomic,assign) BOOL isCpAuth;
//曲作者
@property (nonatomic,copy) NSString *songAuthorName;
//词作者
@property (nonatomic,copy) NSString *lyricAuthorName;
//专辑名称列表, 数组元素为NSString
@property (nonatomic,copy) NSArray *albumNames;
//歌曲时间长度
@property (nonatomic,copy) NSString *length;
//歌曲的语种
@property (nonatomic,copy) NSString *language;
//歌手ID
@property (nonatomic,copy) NSString *singerId;

//只能获取本地的itunes音乐可用，其他接口无效
@property (nonatomic,strong) UIImage *localIconImage;
//是否已缓存
@property (nonatomic,assign) BOOL isCached;

//收藏时间（毫秒）-删除
//@property (nonatomic,copy) NSString *collectionTime;

@end



//收藏歌单信息
@interface SheetInfo : NSObject
//收藏歌单id 取值为0时系统为用户分配的默认歌单
@property (nonatomic,copy) NSString *sheetId;
//收藏歌单名称
@property (nonatomic,copy) NSString *sheetName;
//收藏歌单创建时间
@property (nonatomic,copy) NSString *createTime;
//歌曲数量
@property (nonatomic,assign) int count;

@end


//音乐歌单信息
@interface MusicSheetInfo : NSObject
//音乐歌单id
@property (nonatomic,copy) NSString *musicSheetId;
//音乐歌单分类id：0 首页歌单 其他 用户自定义歌单
@property (nonatomic,assign) int typeId;
//音乐歌单名称
@property (nonatomic,copy) NSString *title;
//音乐歌单描述
@property (nonatomic,copy) NSString *desc;
//音乐歌单图片地址
@property (nonatomic,copy) NSString *imgUrl;
//音乐歌单图片地址(缩略图）
@property (nonatomic,copy) NSString *smallImgUrl;
//音乐歌单试听次数
@property (nonatomic,assign) int auditionCount;
//最小节拍
@property (nonatomic,assign) int minBpm;
//最大节拍
@property (nonatomic,assign) int maxBpm;
//是否已收藏
@property (nonatomic,assign) BOOL isCollection;
//歌单下歌曲总数
@property (nonatomic,assign) int musicCount;
@end

//当前播放歌曲状态
@interface MusicStatus : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
//播放或暂停状态（1:play；0:pause）
@property (nonatomic,assign) int playOrPause;
//歌曲总长度(秒)
@property (nonatomic,assign) int musicLength;
//当前播放时长(秒)
@property (nonatomic,assign) int playLength;
@end

//当前运动状态
@interface SportStatus : NSObject
//运动的形式。0:步行；1：室内跑；2:室外跑；3:骑行
@property (nonatomic,assign) int sport_type;
//速度(米/秒)。连续数值，-1为取数失败。
@property (nonatomic,assign) float speed;
//步频(步/分）。连续数值，-1为取数失败。
@property (nonatomic,assign) int freq;
//体能状态。1-5分别为：很差、差、一般、好、很好；-1：取数失败。
@property (nonatomic,assign) int powerStatus;
@end

//响应对象基础类
@interface BasicResp : NSObject
//返回码
@property (nonatomic,copy) NSString *resCode;
//返回信息
@property (nonatomic,copy) NSString *resMsg;
@end

#pragma mark -- 用户信息同步接口
//请求参数对象
@interface CollectUserIndividuationInfoReq : NSObject
//用户Id
@property (nonatomic,copy) NSString *userId;
//性别
@property (nonatomic,copy) NSString *sex;
//身高
@property (nonatomic,copy) NSString *height;
//体重
@property (nonatomic,copy) NSString *weight;
//出生年月日
@property (nonatomic,copy) NSString *birthday;
//力量
@property (nonatomic,copy) NSString *strength;
//耐力
@property (nonatomic,copy) NSString *endurance;
//偏好（比如：场景_偏好1，场景_偏好2，场景_偏好3，场景_偏好4，流派_偏好1，流派_偏好2，流派_偏好3，流派_偏好4，语种_偏好1，语种_偏好2，语种_偏好3，语种_偏好4）
@property (nonatomic,copy) NSString *tag_Love;
@end

//响应参数对象
@interface CollectUserIndividuationInfoResp : BasicResp
@end

#pragma mark -- 设置播放列表接口
//请求参数对象
@interface SetMusicPlayListReq : NSObject
//歌曲Id数组
@property (nonatomic,copy) NSMutableArray *musicIdList;
//开始播放的起始位置（0起始）
@property (nonatomic,assign) int startIndex;
@end

//响应参数对象
@interface SetMusicPlayListResp : BasicResp
@end

#pragma mark -- 清空播放列表接口
//无请求参数对象

//响应参数对象
@interface ClearMusicPlayListResp : BasicResp
@end

#pragma mark -- 获取播放列表（分页查询）接口

//请求参数对象
@interface GetMusicPlayListReq : NSObject
//分页起始索引（索引从0开始）
@property (nonatomic,assign) int startNum;
//分页结束索引（索引从0开始）
@property (nonatomic,assign) int endNum;
@end

//响应参数对象
@interface GetMusicPlayListResp : BasicResp
//歌曲总数
@property (nonatomic,assign) int count;
//歌曲信息列表
@property (nonatomic,copy) NSMutableArray *musicInfoList;
@end

#pragma mark -- 获取当前播放歌曲接口

//无请求参数对象

//响应参数对象
@interface GetCurrentPlayingMusicResp : BasicResp
//歌曲信息
@property (nonatomic,retain) MusicInfo *musicInfo;
//歌曲在播放列表中的位置索引（0起始）
@property (nonatomic,assign) int musicPosition;

@end

#pragma mark -- 设置歌曲播放模式接口
//请求参数对象
@interface SetMusicPlayModeReq : NSObject
//0：单曲循环；1：循环；2:随机
@property (nonatomic,assign) int playMode;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface SetMusicPlayModeResp : BasicResp
@end

#pragma mark -- 播放，暂停，结束接口
//请求参数对象
@interface SetCurrentMusicStateReq : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
//1：播放；2：暂停；0：结束
@property (nonatomic,assign) int musicState;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface SetCurrentMusicStateResp : BasicResp
@end

#pragma mark -- 设置上一首、下一首歌曲接口
//请求参数对象
@interface SetCurrentMusicPrevOrNextReq : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
//0：上一首；1：下一首
@property (nonatomic,assign) int flag;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface SetCurrentMusicPrevOrNextResp : BasicResp
@end

#pragma mark -- 收藏歌曲接口
//请求参数对象
@interface CollectMusicReq : NSObject
//用户Id
//@property (nonatomic,copy) NSString *userId;
//歌曲列表
@property (nonatomic,copy) NSMutableArray *musicIds;
//收藏歌单ID
@property (nonatomic,copy) NSString *sheetId;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface CollectMusicResp : BasicResp
@end

#pragma mark -- 取消收藏歌曲接口
//请求参数对象
@interface CancelCollectionReq : NSObject
//用户Id
//@property (nonatomic,copy) NSString *userId;
//歌曲列表
@property (nonatomic,copy) NSMutableArray *musicIds;
//收藏歌单ID
@property (nonatomic,copy) NSString *sheetId;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface CancelCollectionResp : BasicResp
@end

#pragma mark -- 获取收藏列表（分页查询）接口

//请求参数对象
@interface GetCollectionMusicListReq : NSObject
//分页起始索引（索引从0开始）
@property (nonatomic,assign) int startNum;
//分页结束索引（索引从0开始）
@property (nonatomic,assign) int endNum;
//收藏歌单ID
@property (nonatomic,copy) NSString *sheetId;
@end

//响应参数对象
@interface GetCollectionMusicListResp : BasicResp
//歌曲总数
@property (nonatomic,assign) int count;
//歌曲信息列表（排序：收藏时间倒序）。
@property (nonatomic,copy) NSMutableArray *musicInfoList;
@end

#pragma mark -- seek定位接口
//请求参数对象
@interface SetCurrentMusicSeekReq : NSObject
//用户Id
//@property (nonatomic,copy) NSString *userId;
//歌曲id
@property (nonatomic,copy) NSString *musicId;
//定位进度1-100
@property (nonatomic,assign) int seek;
@end

//响应参数对象
@interface SetCurrentMusicSeekResp : BasicResp
@end

#pragma mark -- 获取当前播放歌曲状态接口

//无请求参数

//响应参数对象
@interface GetCurrentPlayingMusicStatusResp : BasicResp
//歌曲状态信息
@property (nonatomic,retain) MusicStatus *musicStatus;
@end
#pragma mark -- 根据专辑id获取专辑信息

@interface AlbumInfo : NSObject

//专辑id
@property (nonatomic,copy) NSString *albumId;
//歌手ID
@property (nonatomic,copy) NSString *singgerId;
//专辑首字母
@property (nonatomic,copy) NSString *albumIni;
//专辑名称
@property (nonatomic,copy) NSString *albumName;
//专辑介绍
@property (nonatomic,copy) NSString *intro;
//专辑图片
@property (nonatomic,copy) NSString *albumPicDir;
//发布时间，格式：YYYYMMDD
@property (nonatomic,copy) NSString *createTime;
//查询结果总条数
@property (nonatomic,copy) NSString *resCounter;
//音乐信息列表（只返回musicId、musicName、singerName、singerId四个字段）
@property (nonatomic,copy) NSArray <MusicInfo *>*musicInfoList;

@end

#pragma mark -- 获取歌曲信息接口

//请求参数对象
@interface GetMusicByIdReq : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
@end

//响应参数对象
@interface GetMusicByIdResp : BasicResp
//歌曲信息
@property (nonatomic,retain) MusicInfo *musicInfo;
@end

#pragma mark -- 通过配速推荐获取歌曲信息接口

//请求参数对象
@interface GetMusicByRecommendReq : NSObject
//配速
@property (nonatomic,assign) float tempo;
//分页起始索引（索引从0开始）
@property (nonatomic,assign) int startNum;
//分页结束索引（索引从0开始）
@property (nonatomic,assign) int endNum;
@end

//响应参数对象
@interface GetMusicByRecommendResp : BasicResp
//歌曲信息列表
@property (nonatomic,copy) NSMutableArray *musicInfoList;
//推荐歌曲数
@property (nonatomic,assign) int count;
@end

#pragma mark -- 获取标签库接口

//无请求参数

//响应参数对象
@interface GetMusicTagGroupListResp : BasicResp
//歌曲信息列表
@property (nonatomic,copy) NSMutableArray *groupInfoList;
@end

#pragma mark -- 通过标签获取歌曲列表（分页查询）接口

//请求参数对象
@interface GetMusicListByTagReq : NSObject
//标签id
@property (nonatomic,copy) NSString *tagId;
//分页起始索引（索引从0开始）
@property (nonatomic,assign) int startNum;
//分页结束索引（索引从0开始）
@property (nonatomic,assign) int endNum;
@end

//响应参数对象
@interface GetMusicListByTagResp : BasicResp
//标签下歌曲总数
@property (nonatomic,assign) int count;
//歌曲信息列表。
@property (nonatomic,copy) NSMutableArray *musicInfoList;
@end

#pragma mark -- 查询音乐歌单接口

//请求参数对象
@interface QueryMusicSheetListReq: NSObject
//音乐歌单分类id: 1 首页歌单
@property (nonatomic,assign) int typeId;
//最小节拍(minBpm、maxBpm同时填写生效,否则不进行bpm过滤)
@property (nonatomic,copy) NSString *minBpm;
//最大节拍(minBpm、maxBpm同时填写生效, 否则不进行bpm过滤)
@property (nonatomic,copy) NSString *maxBpm;
@end

//响应参数对象
@interface QueryMusicSheetListResp : BasicResp
//音乐歌单列表。
@property (nonatomic,copy) NSMutableArray *musicSheetInfoList;
@end

#pragma mark -- 查询音乐歌单下歌曲（分页查询）接口

//请求参数对象
@interface QueryMusicListByMusicSheetReq : NSObject

//分页起始索引（索引从0开始）
@property (nonatomic,assign) int startNum;
//分页结束索引（索引从0开始）
@property (nonatomic,assign) int endNum;
//音乐歌单id
@property (nonatomic,copy) NSString *musicSheetId;
@end

//响应参数对象
@interface QueryMusicListByMusicSheetResp : BasicResp
//标签下歌曲总数
@property (nonatomic,assign) int count;
//歌曲信息列表。
@property (nonatomic,copy) NSMutableArray *musicInfoList;
@end

#pragma mark -- 查询收藏歌单接口

//请求参数对象
@interface QuerySheetListReq: NSObject
//分页起始位,默认0
@property (nonatomic,assign) int startNum;
//分页结束位,默认20
@property (nonatomic,assign) int endNum;
@end

//响应参数对象
@interface QuerySheetListResp : BasicResp
//收藏歌单列表。
@property (nonatomic,copy) NSMutableArray *sheetInfoList;
//收藏歌单数量。
@property (nonatomic,assign) int count;
@end

#pragma mark -- 新增收藏歌单接口

//请求参数对象
@interface AddSheetListReq: NSObject
//要添加到该收藏歌单的歌曲列表
@property (nonatomic,copy) NSMutableArray *musicIds;
//收藏歌单名称
@property (nonatomic,copy) NSString *sheetName;
//当前运动状态信息
@property (nonatomic,retain) SportStatus *sportStatus;
@end

//响应参数对象
@interface AddSheetListResp : BasicResp
//歌单ID
@property (nonatomic,copy) NSString *sheetId;
@end

#pragma mark -- 删除收藏歌单接口

//请求参数对象
@interface DelSheetListReq: NSObject
//歌单ID
@property (nonatomic,copy) NSString *sheetId;
@end
//响应参数对象
@interface DelSheetListResp : BasicResp
@end

#pragma mark -- 修改收藏歌单接口

//请求参数对象
@interface ModifySheetListReq: NSObject
//收藏歌单ID
@property (nonatomic,copy) NSString *sheetId;
//收藏歌单名称
@property (nonatomic,copy) NSString *sheetName;
@end
//响应参数对象
@interface ModifySheetListResp : BasicResp
@end

#pragma mark -- 试听次数计数接口

//请求参数对象
@interface CountMusicPlayTimesReq: NSObject
//计数类型：
//1-	音乐歌单试听次数
//2-	歌曲试听次数
//3-	歌曲收藏次数
//4-	歌曲点赞次数
//5-    歌曲分享次数
@property (nonatomic,assign) int type;
//歌曲或歌单ID
@property (nonatomic,copy) NSString *id;
//需要累积的次数,默认+1
@property (nonatomic,assign) int count;
@end
//响应参数对象
@interface CountMusicPlayTimesResp : BasicResp
@end

#pragma mark -- 关键字搜索歌曲接口

//请求参数对象
@interface SearchMusicByKeywordReq: NSObject
//关键字
@property (nonatomic,copy) NSString *key;
//关键字类型 2：歌曲名搜索歌曲 3：歌词搜索歌曲
@property (nonatomic,assign) int keyType;
//当前页(起始页为1)
@property (nonatomic,assign) int pageIndex;
//每页条数，[0 –20]
@property (nonatomic,assign) int pageSize;
@end
//响应参数对象
@interface SearchMusicByKeywordResp : BasicResp
//搜索结果条数
@property (nonatomic,assign) int count;
//歌曲信息列表。
@property (nonatomic,copy) NSMutableArray *musicInfoList;
@end

#pragma mark -- 收藏音乐歌单接口
//请求参数对象
@interface CollectMusicSheetReq : NSObject
//音乐歌单id列表
@property (nonatomic,copy) NSMutableArray *musicSheetIds;
@end

//响应参数对象
@interface CollectMusicSheetResp : BasicResp
@end

#pragma mark -- 取消收藏音乐歌单接口
//请求参数对象
@interface CancelCollectMusicSheetReq : NSObject
//音乐歌单id列表
@property (nonatomic,copy) NSMutableArray *musicSheetIds;
@end

//响应参数对象
@interface CancelCollectMusicSheetResp : BasicResp
@end

#pragma mark -- 查询已收藏音乐歌单列表接口

//请求参数对象
@interface QueryCollectedMusicSheetListReq: NSObject
//分页起始位,默认0
@property (nonatomic,assign) int startNum;
//分页结束位,默认20
@property (nonatomic,assign) int endNum;
@end

//响应参数对象
@interface QueryCollectedMusicSheetListResp : BasicResp
//收藏歌单列表。
@property (nonatomic,copy) NSMutableArray *musicSheetInfoList;
//总数量。
@property (nonatomic,assign) int count;
@end

#pragma makr -- 根据歌曲ID获取歌曲基本信息

//请求参数对象
@interface GetMusicInfoByMusicIdReq : NSObject
//歌曲id
@property (nonatomic,copy) NSString *musicId;
@end

//响应参数对象
@interface GetMusicInfoByMusicIdResp : BasicResp
//歌曲信息
@property (nonatomic,retain) MusicInfo *musicInfo;
@end
#pragma mark - 新的搜索接口
@interface AlbumNew : NSObject
// 专辑的id
@property (copy, nonatomic) NSString *id;
// 专辑名称
@property (copy, nonatomic) NSString *name;
// 1普通2数字专辑
@property (assign, nonatomic) int type;
// 18位id，当为数字专辑时（type为2），该字段有效，否则该字段为空字符串
@property (copy, nonatomic) NSString *dalbumID;
// 12位id，当为数字专辑时（type为2），该字段有效，否则该字段为空字符串
@property (copy, nonatomic) NSString *copyrightID;
// 专辑别名
@property (strong, nonatomic) NSMutableArray <NSString *>*aliasNames;
// 匹配到的歌曲名称
@property (copy, nonatomic) NSString *matchSongName;
// 高亮词
@property (strong, nonatomic) NSMutableArray <NSString *>*highlightStr;
// 专辑发布时间，yyyy-MM-dd
@property (copy, nonatomic) NSString *publishDate;
// 歌手信息
@property (strong, nonatomic) NSMutableArray *singers;
// 专辑图片
@property (copy, nonatomic) NSString *albumPic;
// 全曲总数
@property (assign, nonatomic) int fullSongTotal;
// 专辑所属影视名称
@property (strong, nonatomic) NSMutableArray <NSString *>*movieNames;
// 专辑所属综艺名称
@property (copy, nonatomic) NSString *programName;
// 歌手名，多歌手使用“ ,”
@property (copy, nonatomic) NSString *singerName;
// 匹配度得分
@property (copy, nonatomic) NSString *lcsscore;

@end

@interface SingerNew : NSObject
// 歌手的id
@property (copy, nonatomic) NSString *id;
// 歌手姓名
@property (copy, nonatomic) NSString *name;
// 艺术家图片地址(小) HTTP URL（注意，现阶段曲库对来源IP做限制，也没有相应的服务能力，门户需要下载到本地后再给用户展示
@property (copy, nonatomic) NSString *artistPicS;
// 高亮词
@property (strong, nonatomic) NSMutableArray <NSString *>*highlightStr;
// 有版权歌曲数量
@property (assign, nonatomic) int songNum;
// 无版权歌曲数量
@property (assign, nonatomic) int noProductCount;
// 专辑数量
@property (assign, nonatomic) int albumNum;
// 全曲总数
@property (assign, nonatomic) int fullSongTotal;
// MV数量
@property (assign, nonatomic) int mvNum;
// 匹配度得分
@property (copy, nonatomic) NSString *lcsscore;
@end
@interface MvPicture : NSObject
// 图片路径
@property (copy, nonatomic) NSString *picPath;
@end

@interface ToneNew : NSObject
// 产品id，18位
@property (copy, nonatomic) NSString *id;
// 版权id， 12或11位。versionNo大于1.3时返回12位的copyrightId，否则返回11位。12位的copyrightId前11位对应之前的11位copyrightId
@property (copy, nonatomic) NSString *copyrightId;
// 价格
@property (copy, nonatomic) NSString *price;
// 有效期
@property (copy, nonatomic) NSString *expireDate;

@end
@interface SongNew : NSObject
// 歌曲id
@property (copy, nonatomic) NSString *id;
// 歌曲名字
@property (copy, nonatomic) NSString *name;
// 高亮词
@property (strong, nonatomic) NSMutableArray <NSString *>*highlightStr;
// 高亮歌词
@property (copy, nonatomic) NSString *highlightLyricStr;
// 匹配到的三行歌词，且第一行含有匹配的歌词，后两行歌词顺序读取显示;如果匹配的搜索歌词位于歌词倒数第二行，显示的三行歌词应该为歌词的倒数三行（其中第二行包含匹配歌词）如果匹配的搜索歌词位于歌词最后一行，只显示两行歌词，且显示的两行歌词应该为歌词的倒数两行（其中第二行包含匹配歌词），不同行之间以’\n’作为换行符
@property (copy, nonatomic) NSString *multiLyricStr;
// 歌手信息
@property (strong, nonatomic) NSMutableArray <SingerNew *>*singers;
// 专辑信息
@property (strong, nonatomic) NSMutableArray <AlbumNew *>*albums;
// 标签信息
@property (strong, nonatomic) NSMutableArray <NSString *>*tags;
// 推荐的歌曲播放地址（字段值为空）
@property (copy, nonatomic) NSString *suggestPlayUrl;
// 歌词地址（字段值为空）
@property (copy, nonatomic) NSString *lyricUrl;
// 歌曲所属影视名称
@property (strong, nonatomic) NSMutableArray <NSString *>*movieNames;
// 歌曲所属电视节目名称
@property (strong, nonatomic) NSMutableArray <NSString *>*televisionNames;
// 歌曲是否有版权，1有版权，0无版权
@property (copy, nonatomic) NSString *copyright;
// 歌词文本内容
@property (copy, nonatomic) NSString *strlyric;
// 彩铃数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*tones;
// 振铃数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*rings;
// 全曲数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*fullSongs;
// mv数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*mvList;
// 无损音源数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*hdList;
// 互联网试听数据
@property (strong, nonatomic) NSMutableArray <ToneNew *>*playList;
// 歌手名，多歌手使用“ ,”
@property (copy, nonatomic) NSString *singerName;
// 匹配度得分
@property (copy, nonatomic) NSString *lcsscore;
// mv图片
@property (strong, nonatomic) NSMutableArray <MvPicture *>*mvPic;

@end

@interface SearchSongNewData :NSObject
// 总记录数
@property (assign, nonatomic) int total;
// 搜索结果详细
@property (strong, nonatomic) NSMutableArray <SongNew *>*result;
// 1-标签下歌曲(默认),2-关键词搜索,3-搜索歌手下歌曲
@property (assign, nonatomic) int resultType;
// 结果是否为缺歌推荐，1是，0不是
@property (assign, nonatomic) int isFromCache;
// 全曲总数
@property (assign, nonatomic) int fullSongTotal;

@end

@interface SemanticResult : NSObject
// 专辑，多个结果用|隔开
@property (copy, nonatomic) NSString *album;
// 歌曲，多个结果用|隔开
@property (copy, nonatomic) NSString *song;
// 综艺，多个结果用|隔开
@property (copy, nonatomic) NSString *variety;
// 歌手，多个结果用|隔开
@property (copy, nonatomic) NSString *singer;
// 标签，多个结果用|隔开
@property (copy, nonatomic) NSString *tag;
// 影视，多个结果用|隔开
@property (copy, nonatomic) NSString *film;

@end
@interface SearchSongNewRsp :NSObject
// 返回码
@property (assign, nonatomic) int rc;
// 错误信息
@property (copy, nonatomic) NSString *error;
// 容错结果
@property (strong, nonatomic) NSMutableArray <NSString *>*correct;
// 搜索歌曲data对象
@property (strong, nonatomic) SearchSongNewData *data;
//
@property (strong, nonatomic) NSMutableArray <SemanticResult *>*semantic;
@end

@interface BestShow : NSObject
// 歌手id/专辑id
@property (copy, nonatomic) NSString *id;
// 歌手名
@property (copy, nonatomic) NSString *singername;
// 歌手别名
@property (strong, nonatomic) NSMutableArray <NSString *>*singeraliasnames;
// 歌手图片
@property (copy, nonatomic) NSString *singerPic;
// 歌手地区
@property (copy, nonatomic) NSString *singerArea;
// 歌手下专辑数
@property (assign, nonatomic) int albumCount;
// 歌手下单曲数
@property (assign, nonatomic) int songCount;
// 歌手下mv数
@property (assign, nonatomic) int mvCount;
// 热门专辑TOP3
@property (strong, nonatomic) NSMutableArray <AlbumNew *>*hotAlbum;
// 热门歌曲TOP3
@property (strong, nonatomic) NSMutableArray <SongNew *>*hotSong;
// 佳展示类型，最佳歌手为singer/最佳专辑为album
@property (copy, nonatomic) NSString *mod;
// 全曲总数
@property (assign, nonatomic) int fullSongTotal;
// 专辑名
@property (copy, nonatomic) NSString *albumname;
// 1普通2数字专辑
@property (assign, nonatomic) int type;
// 专辑歌手
@property (strong, nonatomic) NSMutableArray <SingerNew *>*singers;
// 专辑图片
@property (copy, nonatomic) NSString *albumPic;
// 专辑简介
@property (copy, nonatomic) NSString *intro;
// 专辑发布时间，Unix时间戳
@property (assign, nonatomic) int publishTime;
@end

@interface TagNew : NSObject
// 标签名称
@property (copy, nonatomic) NSString *name;
// 高亮词
@property (strong, nonatomic) NSMutableArray <NSString *>*highlightStr;
// 匹配度得分
@property (copy, nonatomic) NSString *lcsscore;
@end

@interface SearchAlbumNewData : NSObject
// 总记录数
@property (assign, nonatomic) int total;
// 搜索结果详细
@property (strong, nonatomic) NSMutableArray <AlbumNew *>*result;
@end

@interface SearchAlbumNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 容错结果
@property (strong, nonatomic) NSMutableArray <NSString *>*correct;
// 搜索专辑data对象
@property (strong, nonatomic) SearchAlbumNewData *data;
// 容错结果类型
@property (strong, nonatomic) NSMutableArray <SemanticResult *>*semantic;

@end

@interface SearchSingerNewData : NSObject
// 总记录数
@property (assign, nonatomic) int total;
// 搜索结果详细
@property (strong, nonatomic) NSMutableArray <SingerNew *>*result;

@end

@interface SearchSingerNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 容错结果
@property (strong, nonatomic) NSMutableArray <NSString *>*correct;
// 搜索歌手data对象
@property (strong, nonatomic) SearchSingerNewData *data;
// 容错结果类型
@property (strong, nonatomic) NSMutableArray <SemanticResult *>*semantic;
@end

@interface BestShowResultData : NSObject
// 总记录数
@property (assign, nonatomic) int total;
// 搜索结果详细
@property (strong, nonatomic) NSMutableArray <BestShow *>*result;
@end

@interface BestShowResult : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 搜索最佳展示data对象
@property (strong, nonatomic) BestShowResultData *data;

@end

@interface SearchAllNewData : NSObject
// 搜索歌曲信息类
@property (strong, nonatomic) SearchSongNewRsp *songResult;
// 搜索专辑信息类
@property (strong, nonatomic) SearchAlbumNewRsp *albumResult;
// 搜索歌手信息类
@property (strong, nonatomic) SearchSingerNewRsp *singerResult;
// 搜索标签下歌曲信息类
@property (strong, nonatomic) SearchSongNewRsp *tagSongResult;
// 搜索最佳展示结果类
@property (strong, nonatomic) BestShowResult *bestShowResult;
@end


@interface SearchAllNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// SearchAllNewData
@property (strong, nonatomic) SearchAllNewData *data;

@end

@interface SearchSuggestNewData : NSObject
// 歌曲数据
@property (strong, nonatomic) NSMutableArray <SongNew *>*songList;
// 专辑数据
@property (strong, nonatomic) NSMutableArray <AlbumNew *>*albumList;
// 歌手数据
@property (strong, nonatomic) NSMutableArray <SingerNew *>*singerList;
// 标签数据
@property (strong, nonatomic) NSMutableArray <TagNew *>*tagList;
@end

@interface SearchSuggestNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 搜索联想搜索data对象
@property (strong, nonatomic) SearchSuggestNewData *data;
@end

@interface SearchSingerSAMNewData : NSObject
// 歌曲数据
@property (strong, nonatomic) SearchSongNewRsp *songResult;
// 专辑数据
@property (strong, nonatomic) SearchAlbumNewRsp *albumResult;

@end

@interface SearchSingerSAMNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 搜索歌手下单曲专辑MVdata对象
@property (strong, nonatomic) SearchSingerSAMNewData *data;

@end

@interface SearchLyricNewData : NSObject
// 总记录数
@property (assign, nonatomic) int total;
// 搜索结果详细
@property (strong, nonatomic) NSMutableArray <SongNew *>*result;
// 1-标签下歌曲(默认),2-关键词搜索,3-搜索歌手下歌曲
@property (assign, nonatomic) int resultType;
// 结果是否为缺歌推荐，1是，0不是
@property (assign, nonatomic) int isFromCache;


@end


@interface SearchLyricNewRsp : NSObject
// 返回码，参见附录
@property (assign, nonatomic) int rc;
// 错误描述信息，该字段仅在rc>0时才返回
@property (copy, nonatomic) NSString *error;
// 容错结果
@property (strong, nonatomic) NSMutableArray <NSString *>*correct;
// 搜索由歌词搜歌曲data对象
@property (strong, nonatomic) SearchLyricNewData *data;
// 容错结果类型
@property (strong, nonatomic) NSMutableArray <SemanticResult *>*semantic;
@end

@interface MiguAppContentItem  : NSObject
// 歌曲ID,如果contentType为2,则值必有
@property (copy, nonatomic) NSString *songId;
// 内容ID
@property (copy, nonatomic) NSString *contentId;
// 内容类型:现只有2-歌曲
@property (copy, nonatomic) NSString *contentType;
// 内容名称
@property (copy, nonatomic) NSString *contentName;
// 内容归属人id
@property (copy, nonatomic) NSString *singerId;
// 内容归属人名称
@property (copy, nonatomic) NSString *singerName;

@end

@interface MiguAppPlayListItem : NSObject
// 播放列表id（歌单ID）,播放列表唯一标识
@property (copy, nonatomic) NSString *playListId;
// 播放列表内容类型:2-歌曲(现只有歌曲)
@property (copy, nonatomic) NSString *playListType;
// 播放列表名称
@property (copy, nonatomic) NSString *playListName;
// 播放列表简介
@property (copy, nonatomic) NSString *summary;
// 播放列表封面图片地址
@property (copy, nonatomic) NSString *image;
// 创建时间
@property (copy, nonatomic) NSString *createTime;
// 更新时间
@property (copy, nonatomic) NSString *updateTime;
// 内容数量,默认为0
@property (copy, nonatomic) NSString *contentCount;
// 内容列表
@property (strong, nonatomic) NSArray < MiguAppContentItem*> *contentList;
// 图片修改方式:1-未手动设置图片,0-手动设
@property (copy, nonatomic) NSString *imageChangeType;

@end



#pragma mark - QNX

@class OPNumItem;
@class ImgItem;

@interface MusicListItem : NSObject
// 歌单更新时间
@property (nonatomic, copy) NSString *publishTime;
// 状态
@property (nonatomic, assign) NSInteger status;
// 歌单作者
@property (nonatomic, copy) NSString *ownerId;
// 歌单作者名称
@property (nonatomic, copy) NSString *ownerName;
// 歌单头像 url
@property (nonatomic, copy) NSString *ownerPic;
// 图片对象
@property (nonatomic, strong) ImgItem *imgItem;
// 行为统计标记
@property (nonatomic, strong) OPNumItem *opNumItem;
// 歌单 Id
@property (nonatomic, copy) NSString *musicListId;
// 歌曲数量
@property (nonatomic, assign) NSInteger musicNum;
// 通用资源类型
@property (nonatomic, copy) NSString *resourceType;
// 标题
@property (nonatomic, copy) NSString *title;
// 简介
@property (nonatomic, copy) NSString *summary;
// 是否用户指定歌单封面
@property (nonatomic, copy) NSString *havePrivatePic;
@property (nonatomic, assign) NSInteger type;
@end

@interface OPNumItem : NSObject
// 点赞次数
@property (nonatomic, assign) NSInteger thumbNum;
@property (nonatomic, copy) NSString *thumbNumDesc;
// 观看次数
@property (nonatomic, assign) NSInteger livePlayNum;
// 播放/浏览次数
@property (nonatomic, assign) NSInteger playNum;
@property (nonatomic, copy) NSString *playNumDesc;
// 人气值
@property (nonatomic, assign) NSInteger popularNum;
@property (nonatomic, copy) NSString *popularNumDesc;
// 分享次数
@property (nonatomic, assign) NSInteger shareNum;
@property (nonatomic, copy) NSString *shareNumDesc;
// 关注次数
@property (nonatomic, assign) NSInteger followNum;
@property (nonatomic, copy) NSString *followNumDesc;
// 购买次数（累计）
@property (nonatomic, assign) NSInteger orderNumByTotal;
@property (nonatomic, copy) NSString *orderNumByTotalDesc;
// 购买次数（周）
@property (nonatomic, assign) NSInteger orderNumByWeek;
@property (nonatomic, copy) NSString *orderNumByWeekDesc;
// 收藏次数
@property (nonatomic, assign) NSInteger keepNum;
@property (nonatomic, copy) NSString *keepNumDesc;
// 评论次数
@property (nonatomic, assign) NSInteger commentNum;
@property (nonatomic, copy) NSString *commentNumDesc;
// 预约次数
@property (nonatomic, assign) NSInteger bookingNum;
// 订阅次数
@property (nonatomic, assign) NSInteger subscribeNum;
@property (nonatomic, copy) NSString *subscribeNumDesc;
@end



@class RelatedItem;
@class SongFormatItem;
@class TagItem;

@interface SongItem : NSObject
// 数字专辑栏目 Id
@property (nonatomic, copy) NSString *digitalColumnId;
// 数字专辑 Id
@property (nonatomic, copy) NSString *dalbumId;
// 专辑名称
@property (nonatomic, copy) NSString *album;
// 该歌曲是否有版权
@property (nonatomic, copy) NSString *copyright;
// 版权 Id
@property (nonatomic, copy) NSString *copyrightId;
// 歌手 Id
@property (nonatomic, copy) NSString *singerId;
// 逐行歌词 url
@property (nonatomic, copy) NSString *lrcUrl;
@property (nonatomic, copy) NSString *isCollection;
// 专辑 Id
@property (nonatomic, copy) NSString *albumId;
@property (nonatomic, copy) NSString *invalidateDate;
@property (nonatomic, copy) NSString *actionImg;
// 唯一标识 Id
@property (nonatomic, copy) NSString *songId;
@property (nonatomic, copy) NSString *songAliasName;
// 是否在数字专辑中
@property (nonatomic, copy) NSString *isInDAlbum;
@property (nonatomic, copy) NSString *songDescs;
@property (nonatomic, copy) NSString *preSale;
@property (nonatomic, copy) NSString *isDownload;
// 下载音质控制
@property (nonatomic, copy) NSString *toneControl;
@property (nonatomic, copy) NSString *logId;
@property (nonatomic, copy) NSString *chargeAuditions;
@property (nonatomic, copy) NSString *isInSalesPeriod;
// 歌手名称
@property (nonatomic, copy) NSString *singer;
// 内容 Id
@property (nonatomic, copy) NSString *contentId;
// 逐字歌词 url
@property (nonatomic, copy) NSString *mrcUrl;
// 歌曲的存在形式
@property (nonatomic, copy) NSString *songType;
@property (nonatomic, copy) NSString *actionUrlParams;
@property (nonatomic, copy) NSString *isInSideDalbum;
@property (nonatomic, copy) NSString *topQuality;
// 歌曲名称
@property (nonatomic, copy) NSString *songName;
// 通用资源类型
@property (nonatomic, copy) NSString *resourceType;
@property (nonatomic, copy) NSString *hasMv;
@property (nonatomic, copy) NSString *vipType;
@property (nonatomic, copy) NSString *isFromCash;
@property (nonatomic, copy) NSString *isShare;
// 下载格式码
@property (nonatomic, strong) NSArray <SongFormatItem *>*rateFormats;
// 图片对象
@property (nonatomic, strong) NSArray <ImgItem *>*albumImgs;
// 关联产品信息
@property (nonatomic, strong) NSArray <RelatedItem *>*relatedSongs;
// 行为统计标记
@property (nonatomic, strong) OPNumItem *opNumItem;
// 标签组
@property (nonatomic, strong) NSArray <TagItem *>*tagList;
@property (nonatomic, strong) NSDictionary *codeRate;
@end

@interface SongFormatItem : NSObject
// 码率类型
@property (nonatomic, copy) NSString *formatType;
// 后缀名
@property (nonatomic, copy) NSString *fileType;
// 价格
@property (nonatomic, copy) NSString *price;
// 格式码
@property (nonatomic, copy) NSString *format;
// 试听/播放/下载原始地址
@property (nonatomic, copy) NSString *url;
// 歌曲大小
@property (nonatomic, copy) NSString *size;
// 播放时长
@property (nonatomic, copy) NSString *length;
// 通用资源类型
@property (nonatomic, copy) NSString *resourceType;
@end

@interface ImgItem : NSObject
// 图片链接
@property (nonatomic, copy) NSString *img;
// 图片大小类型
@property (nonatomic, copy) NSString *imgSizeType;
// 歌单图片 Id
@property (nonatomic, copy) NSString *fileId;
@end

@interface RelatedItem : NSObject
// 资源类型
@property (nonatomic, copy) NSString *resourceType;
// 资源类型名称
@property (nonatomic, copy) NSString *resourceTypeName;
// 版权 Id
@property (nonatomic, copy) NSString *copyrightId;
// 产品 Id
@property (nonatomic, copy) NSString *productId;
@end

@interface TagItem : NSObject
// 通用资源类型
@property (nonatomic, copy) NSString *resourceType;
// 标签 Id
@property (nonatomic, copy) NSString *tagId;
// 标签名称
@property (nonatomic, copy) NSString *tagName;
// 标签描述
@property (nonatomic, copy) NSString *tagDesc;
// 标签图片路径
@property (nonatomic, copy) NSString *tagPicUrl;
@end
