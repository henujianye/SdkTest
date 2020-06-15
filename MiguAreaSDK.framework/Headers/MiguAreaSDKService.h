//
//  MiguAreaSDKService.h
//  MiguArea
//
//  Created by Chris on 6/6/18.
//  Copyright © 2018 migu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MiGuAreaMusicObjects.h"

@interface MiguAreaSDKService : NSObject

/**
 初始化SDK，并设置相关参数

 @param smartDeviceId 唯一智能设备标识码【最大128位】, 【第1位加第2位标识类型，10-车载音乐,11-智能音箱，12-可穿戴设备等等 ,必须设置，否则可能无法获取指定渠道的资源 (必传参数)
 @param userId  获取歌单前必须先设置userId，否则获取不到数据 (必传参数)
 @param phoneNo 手机号码，登录用户提供 (非必传参数)
 @param appID 在开发者门户上，申请创建应用时获得AppID。 (非必传参数)
 @param key 加密渠道号。(必传参数)
 @param channel 未加密渠道号。(非必传参数)
 @param subchannel 未加密子渠道号。(非必传参数)

 */
+ (void) startWithSmartDeviceId:(NSString *) smartDeviceId
                         userId:(NSString *) userId
                        phoneNo:(NSString *) phoneNo
                          appID:(NSString *) appID
                            key:(NSString *) key
                        channel:(NSString *) channel
                     subchannel:(NSString *) subchannel;

#pragma mark - 歌曲相关
/**
 获取标签列表

 @param success 成功
 @param failure 失败
 */
+ (void)findAllTagListSuccess:(void (^)(NSArray <GroupInfo *>* taginfoList))success
                      faliure:(void (^)(NSError *error))failure;
/**
 通过标签的id获取歌曲信息

 @param tagId 标签的id
 @param startNum 分页起始位 (非负数，建议起始值为0 ）
 @param endNum 分页结束位 （大于startNum的值，建议值为20，最大范围为endNum - startNum <=50)
 @param success 成功
 @param failure 失败
 */
+ (void)findSongPageByTagId:(NSString * _Nonnull)tagId
                   startNum:(NSInteger)startNum
                     endNum:(NSInteger)endNum
                    success:(void (^)(NSArray <MusicInfo *>* musicList))success
                    faliure:(void (^)(NSError *error))failure;

/**
 获取首页下的歌单

 @param typeId 类型  （默认是@“1” : 首页）（非必传）
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)findMusicSheetTypeId:(NSString *_Nullable)typeId
                     success:(void (^)(NSArray <MusicSheetInfo *> *musicSheetList))success
                     faliure:(void (^)(NSError *error))failure;


/**
 查询歌单下的歌曲

 @param musicSheetId 歌单的id
 @param startNum 分页起始位 (非负数，建议起始值为0 ）
 @param endNum 分页结束位 （大于startNum的值，建议值为20，最大范围为endNum - startNum <=50)
 @param success 成功信息 （count: 总个数）
 @param failure 失败信息
 */
+ (void)findSongByMusicSheetId:(NSString * _Nonnull)musicSheetId
                      startNum:(NSInteger)startNum
                        endNum:(NSInteger)endNum
                       success:(void (^)(NSArray <MusicInfo *>* musicList,long count))success
                       faliure:(void (^)(NSError *error))failure;

/**
 计数接口（歌曲或者歌单）

 @param type 计数类型：1:音乐歌单试听次数
 @param parmaId 歌曲或歌单ID
 @param number 需要累积的次数,默认:1 不能为:0
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)updateMusicCountType:(NSString * _Nonnull)type
                     parmaId:(NSString * _Nonnull)parmaId
                       count:(NSInteger)number
                     success:(void (^)(void))success
                     faliure:(void (^)(NSError *error))failure;


/**
 智能推荐（获取推荐的歌曲）

 @param tempo 配速(min/km)
 @param startNum 分页起始位 (非负数，建议起始值为0 ）
 @param endNum 分页结束位 （大于startNum的值，建议值为20，最大范围为endNum - startNum <=50)
 @param success 成功信息 （count: 总个数）
 @param failure 失败信息
 */
+ (void)findRecommendSongTempo:(NSInteger)tempo
                      startNum:(NSInteger)startNum
                        endNum:(NSInteger)endNum
                       success:(void (^)(NSArray <MusicInfo *>* musicList,long count))success
                       faliure:(void (^)(NSError *error))failure;

/**
 通过歌曲的版权id查询歌曲信息

 @param copyrightId 歌曲版权id 必传 （不能为空)
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)findSongById:(NSString * _Nonnull)copyrightId
             success:(void (^)( MusicInfo * musinInfo))success
             faliure:(void (^)(NSError *error))failure;
/**
 根据专辑id获取歌曲信息
 
 @param albumId 专辑的id 不能为nil
 @param pageNumber 当前的页数 默认为1
 @param numberPerPage 每页条数，[0 – 30] ，默认每页10条
 @param success 成功信息(返回 AlbumInfo对象)
 @param failure 失败信息
 */
+(void)findSongByAlbumId:(NSString * _Nonnull)albumId
              pageNumber:(NSInteger )pageNumber
           numberPerPage:(NSInteger)numberPerPage
                 success:(void (^)(AlbumInfo *albumInfo))success
                 faliure:(void (^)(NSError *error))failure;

/**
 获取电台信息,需要自己根据截图来看，因为目前后台并没有告诉具体的返回类型
 
 @param success 成功的信息 包含json字符串
 @param failure 失败的信息
 */
+ (void)getRadioMessageSuccess:(void (^)(NSString * jsonStr))success
                       failure:(void(^)(NSError *error))failure;
/**
 获取歌单信息，需要自己根据截图来看，因为目前后台并没有告诉具体的返回类型
 
 @param success 成功的信息 包含json字符串
 @param failure 失败的信息
 */
+ (void)getPlayListMessageSuccess:(void (^)(NSString * jsonStr))success
                          failure:(void(^)(NSError *error))failure;

/**
 获取新碟速递信息 ,需要自己根据截图来看，因为目前后台并没有告诉具体的返回类型
 
 @param success 成功的信息 包含json字符串
 @param failure 失败的信息
 */
+ (void)getNewAlbumMessageSuccess:(void (^)(NSString * jsonStr))success
                          failure:(void(^)(NSError *error))failure;

/**
 获取新歌速递信息,需要自己根据截图来看，因为目前后台并没有告诉具体的返回类型
 
 @param success 成功的信息 包含json字符串
 @param failure 失败的信息
 */
+(void)getNewSongMessageSuccess:(void (^)(NSString * jsonStr))success
                        failure:(void(^)(NSError *error))failure;

/**
 获取榜单信息,需要自己根据截图来看，因为目前后台并没有告诉具体的返回类型
 
 @param success 成功的信息 包含json字符串
 @param failure 失败的信息
 */
+(void)getRankMessageSuccess:(void (^)(NSString * jsonStr))success
                     failure:(void(^)(NSError *error))failure;

/**
 获取咪咕音乐歌单下的内容
 
 @param playListId 咪咕音乐客户端提供的歌单id ，必传 不能为空
 @param playListType 歌单下内容类型：2 歌曲（默认）非必传
 @param success 成功的信息 返回MiguAppPlayListItem类型
 @param failure 失败的信息
 */
+(void)getPlayListContentByPlayListId:(NSString * _Nonnull)playListId
                         playListType:(NSString * _Nullable)playListType
                              success:(void(^)(MiguAppPlayListItem *playList))success
                              failure:(void(^)(NSError *error))failure;


#pragma mark - 搜索相关的
/**
 关键字搜索歌曲 老的接口

 @param keyWord 关键字 不能为空
 @param keyType 关键字类型 1歌手名搜索歌手 2歌曲名搜索歌曲 3歌词搜索歌曲
 @param pageIndex 当前页(起始页为1)
 @param pageSize 每页条数，[1 –20]
 @param success 成功信息 （count: 总个数）
 @param failure 失败信息
 */
+ (void)searchMusicByKeyOldKeyWord:(NSString * _Nonnull)keyWord
                           keyType:(NSString * _Nonnull)keyType
                         pageIndex:(NSInteger)pageIndex
                          pageSize:(NSInteger)pageSize
                           success:(void (^)(NSArray <MusicInfo *>* musicList,long count))success
                           faliure:(void (^)(NSError *error))failure;
#pragma mark - 新的搜索接口。分为8个类型
/**
 关键字搜索歌曲 新的接口
 
 @param text 关键字 不能为空
 @param pageIndex  当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param searchType 搜索类型 1.智能搜索,2.关键词搜索(默认)
 @param issemantic 1.语义搜索(默认),0.不走语义
 @param isCorrect 0.关闭，1.开启（默认）
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchSongByKey:(NSString * _Nonnull)text
              pageIndex:(NSInteger)pageIndex
               pageSize:(NSInteger)pageSize
             searchType:(NSInteger)searchType
             issemantic:(NSInteger)issemantic
              isCorrect:(NSInteger)isCorrect
                success:(void (^)(SearchSongNewRsp *songNewRep))success
                faliure:(void (^)(NSError *error))failure;

/**
 关键字搜索专辑 新的接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param issemantic 1.语义搜索(默认),0.不走语义
 @param isCorrect 0.关闭，1.开启（默认）
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchAlbumByKey:(NSString * _Nonnull)text
               pageIndex:(NSInteger)pageIndex
                pageSize:(NSInteger)pageSize
              issemantic:(NSInteger)issemantic
               isCorrect:(NSInteger)isCorrect
                 success:(void (^)(SearchAlbumNewRsp *albumNewRep))success
                 faliure:(void (^)(NSError *error))failure;

/**
 关键字搜索歌手 新的接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param issemantic 1.语义搜索(默认),0.不走语义
 @param isCorrect 0.关闭，1.开启（默认）
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchSingerByKey:(NSString * _Nonnull)text
                pageIndex:(NSInteger)pageIndex
                 pageSize:(NSInteger)pageSize
               issemantic:(NSInteger)issemantic
                isCorrect:(NSInteger)isCorrect
                  success:(void (^)(SearchSingerNewRsp *singerNewRep))success
                  faliure:(void (^)(NSError *error))failure;

/**
 关键字搜索标签下歌曲 新的接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param issemantic 1.语义搜索(默认),0.不走语义
 @param isCorrect 0.关闭，1.开启（默认）
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchSongInTagByKey:(NSString * _Nonnull)text
                   pageIndex:(NSInteger)pageIndex
                    pageSize:(NSInteger)pageSize
                  issemantic:(NSInteger)issemantic
                   isCorrect:(NSInteger)isCorrect
                     success:(void (^)(SearchSongNewRsp *songNewRep))success
                     faliure:(void (^)(NSError *error))failure;



/**
 无维度搜素 新的搜索接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param searchType 搜索类型 1.智能搜索,2.关键词搜索(默认)
 @param isCorrect 0.关闭，1.开启（默认）
 @param success 成功信息
 @param failure 失败信
 */
+ (void)searchDimensionsByKey:(NSString * _Nonnull)text
                    pageIndex:(NSInteger)pageIndex
                     pageSize:(NSInteger)pageSize
                   searchType:(NSInteger)searchType
                    isCorrect:(NSInteger)isCorrect
                      success:(void (^)(SearchAllNewRsp *allNewRep))success
                      faliure:(void (^)(NSError *error))failure;

/**
 联想搜索 新的搜索接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param success 成功信息
 @param failure 失败信
 */
+ (void)searchLenovoByKey:(NSString * _Nonnull)text
                pageIndex:(NSInteger)pageIndex
                 pageSize:(NSInteger)pageSize
                  success:(void (^)(SearchSuggestNewRsp *suggestNewRep))success
                  faliure:(void (^)(NSError *error))failure;

/**
 搜索歌手下单曲专辑MV 新的搜索接口
 
 @param singerId 不能为空 歌手的id
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchSingerSAMByKey:(NSString * _Nonnull)singerId
                  pageIndex:(NSInteger)pageIndex
                   pageSize:(NSInteger)pageSize
                    success:(void (^)(SearchSingerSAMNewRsp *singerSAMRep))success
                    faliure:(void (^)(NSError *error))failure;

/**
 歌词搜索歌曲 新的搜索接口
 
 @param text 关键字 不能为空
 @param pageIndex 当前页(起始页为1),默认为1
 @param pageSize 每页条数，[0-50],默认为15
 @param success 成功信息
 @param failure 失败信息
 */
+ (void)searchLyricByKey:(NSString * _Nonnull)text
               pageIndex:(NSInteger)pageIndex
                pageSize:(NSInteger)pageSize
                 success:(void (^)(SearchLyricNewRsp *lyricNewRsp))success
                 faliure:(void (^)(NSError *error))failure;
#pragma mark -- 收藏相关

/**
 将一首歌曲添加到用户收藏列表，用户存在默认歌单 ID 为 0，当 sheetId 为空时，歌曲将添加到默认歌单中。(支持2.0)

 @param musicId 收藏歌曲列表，内容是歌曲 ID 字符串
 @param sheetId （可选）自定义歌单 ID，默认值 0；系统为用户分配默认歌单 ID 为 0，当 sheetId 为空时，歌曲将添加到默认歌单中
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)addMusicCollection:(NSArray *)musicId
                   sheetId:(NSString *)sheetId
                 onSuccess:(void(^)(void))success
                 onFailure:(void(^)(NSError *error))failure;


/**
 将用户已存在收藏列表中的歌曲移除收藏。(支持2.0)

 @param musicId 收藏歌曲列表，内容是歌曲 ID 字符串
 @param sheetId （可选）自定义歌单 ID，默认值 0；系统为用户分配默认歌单 ID 为 0，当 sheetId 为空时，将取消默认歌单中歌曲
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)cancelMusicCollection:(NSArray *)musicId
                      sheetId:(NSString *)sheetId
                    onSuccess:(void(^)(void))success
                    onFailure:(void(^)(NSError *error))failure;


/**
 查询收藏歌单下歌曲。(支持2.0)

 @param startNum 分页起始位（非负数，起始值 0）
 @param endNum 分页结束位（大于 startNum 的值，建议值为 20，最大范围为 endNum - startNum <= 50）
 @param sheetId （可选）自定义收藏歌单 ID；默认值 0；系统为用户分配默认歌单 ID 为 0，当 sheetId 为空时，将查询默认歌单中歌曲
 @param success （可选）成功的 task，数组中的对象类型是 MusicInfo，count 为总个数
 @param failure （可选）失败的 task
 */
+ (void)findMusicCollectionPage:(NSInteger)startNum
                            end:(NSInteger)endNum
                        sheetId:(NSString *)sheetId
                      onSuccess:(void(^)(NSArray *list, NSInteger count))success
                      onFailure:(void(^)(NSError *error))failure;



/**
 将音乐歌单添加到用户收藏列表

 @param sheetId 音乐歌单列表，内容是歌单 ID 字符串
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)addMusicSongListCollection:(NSArray *)sheetId
                         onSuccess:(void(^)(void))success
                         onFailure:(void(^)(NSError *error))failure;


/**
 将用户已存在收藏列表中的音乐歌单移除收藏

 @param sheetId 音乐歌单列表，内容是歌单 ID 字符串
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)cancelMusicSongListCollection:(NSArray *)sheetId
                            onSuccess:(void(^)(void))success
                            onFailure:(void(^)(NSError *error))failure;


/**
 查询收藏音乐歌单

 @param startNum 分页起始位（非负数，起始值 0）
 @param endNum 分页结束位（大于 startNum 的值，建议值为 20，最大范围为 endNum - startNum <= 50）
 @param success （可选）成功的 task，数组中的对象类型是 MusicSheetInfo，count 为总个数
 @param failure （可选）失败的 task
 */
+ (void)findMusicSongListCollectionPage:(NSInteger)startNum
                                    end:(NSInteger)endNum
                              onSuccess:(void(^)(NSArray *list, NSInteger count))success
                              onFailure:(void(^)(NSError *error))failure;



/**
 用户创建新的歌单，(支持2.0)

 @param musicId （可选）歌曲列表，内容是歌曲 ID 字符串
 @param sheetName 歌单名称
 @param success （可选）成功的 task，sheetId 是新创建歌单的 ID
 @param failure （可选）失败的 task
 */
+ (void)createCustomSongListCollection:(NSArray *)musicId
                             sheetName:(NSString *)sheetName
                             onSuccess:(void(^)(NSString *sheetId))success
                             onFailure:(void(^)(NSError *error))failure;


/**
 用户删除已创建的歌单，注意不能删除默认（sheetId 为 0）的歌单。(支持2.0)

 @param sheetId 自定义收藏歌单 ID
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)deleteCustomSongListCollection:(NSString *)sheetId
                             onSuccess:(void(^)(void))success
                             onFailure:(void(^)(NSError *error))failure;


/**
 用户编辑歌单的信息。(支持2.0)

 @param sheetId 自定义收藏歌单 ID
 @param sheetName 歌单名称
 @param success （可选）成功的 task
 @param failure （可选）失败的 task
 */
+ (void)updateCustomSongListCollection:(NSString *)sheetId
                             sheetName:(NSString *)sheetName
                             onSuccess:(void(^)(void))success
                             onFailure:(void(^)(NSError *error))failure;


/**
 查询用户歌单列表。(支持2.0)

 @param startNum 分页起始位（非负数，起始值 0）
 @param endNum 分页结束位（大于 startNum 的值，建议值为 20，最大范围为 endNum - startNum <= 50）
 @param success （可选）成功的 task，数组中的对象类型是 SheetInfo，count 为总个数
 @param failure （可选）失败的 task
 */
+ (void)findCustomSongListCollection:(NSInteger)startNum
                                 end:(NSInteger)endNum
                           onSuccess:(void(^)(NSArray *list, NSInteger count))success
                           onFailure:(void(^)(NSError *error))failure;

#pragma mark 获取本地itunes音乐
/**
 获取本地的itunes音乐,需要在info.plist添加NSAppleMusicUsageDescription，如：
 <key>NSAppleMusicUsageDescription</key>
 <string>是否允许访问本地音乐？</string>
 
 @param complete 完成的操作，其中allSongsList存放都是MusicInfo模型
 singersList存放都是字典，其中字典的key：歌手名字，values：歌手对应的歌曲数组（musicinfo模型）
 albumsList存放都是字典，其中字典的key：专辑名字，values：专辑对应的歌曲数组（musicinfo模型）
 */
+ (void)getLocalItunesMusic:(void (^)(NSArray <MusicInfo *> * allSongsList,
                                      NSArray <NSMutableDictionary *> *singersList,
                                      NSArray <NSMutableDictionary *> *albumsList))complete;




#pragma mark - 设备相关

/**
 设备ID查询设备信息接口；根据智能设备唯一识别号查询智能设备信息。

 @param deviceKey 查询设备的秘钥
 @param success 成功信息(详见文档)
 @param failure 失败信息
 */
+ (void)queryDeviceInfoByDeviceKey:(NSString *) deviceKey
                           Success:(void (^)(NSDictionary *responseObj))success
                           faliure:(void (^)(NSError *error))failure;



#pragma mark - QNX

/**
 获取个人创建的歌单列表

 @param pageNo 请求页码，默认1
 @param pageSize 每页数量，默认10
 @param success （可选）成功的 task，数组中的对象类型是 MusicListItem，count 为总个数
 @param failure （可选）失败的 task
 */
+ (void)findQNXSongListCollection:(NSInteger)pageNo
                         pageSize:(NSInteger)pageSize
                        onSuccess:(void(^)(NSArray *list, NSInteger count))success
                        onFailure:(void(^)(NSError *error))failure;

/**
 获取歌单中的歌曲列表

 @param pageNo 请求页码，默认1
 @param pageSize 每页数量，默认10
 @param musicListId 歌单 Id
 @param success （可选）成功的 task，数组中的对象类型是 SongItem，count 为总个数，publishTime 为发布时间
 @param failure （可选）失败的 task
 */
+ (void)findQNXMusicCollectionPage:(NSInteger)pageNo
                          pageSize:(NSInteger)pageSize
                       musicListId:(NSString *)musicListId
                         onSuccess:(void(^)(NSArray *list, NSInteger count, NSString *publishTime))success
                         onFailure:(void(^)(NSError *error))failure;

@end
