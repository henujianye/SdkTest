//
//  MiguAreaSDKAudioPlayer.h
//  MiguAreaSDK
//
//  Created by apple on 2018/8/28.
//  Copyright © 2018年 migu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MiGuAreaMusicObjects.h"

typedef NS_ENUM(NSUInteger, MiguAreaSDKAudioPlayerStatus){
    MiguAreaSDKAudioPlayerStatusBuffering = 1,              //缓冲
    MiguAreaSDKAudioPlayerStatusPlaying = 2,                //播放
    MiguAreaSDKAudioPlayerStatusPause = 3,                  //暂停
    MiguAreaSDKAudioPlayerStatusStop = 4,                   //停止
    MiguAreaSDKAudioPlayerStatusInterruptByBluetooth = 5,   //由于蓝牙关闭导致的系统暂停
};

typedef NS_ENUM(NSUInteger, MiguAreaSDKAudioPlayerMode){
    MiguAreaSDKAudioPlayerModeSequenceLoop = 1,         //列表循环
    MiguAreaSDKAudioPlayerModeSingleLoop = 2,           //单曲循环
    MiguAreaSDKAudioPlayerModeRandom = 3,               //随机播放
};

@protocol MiguAreaSDKAudioPlayerDelegate <NSObject>

#pragma mark - 远程控制相关回调
/**
 *  播放器会通过以下远程控制相关回调返回值决定是否在播放器内部处理相关控制逻辑，若返回为YES，请在外部处理相关控制逻辑；若返回为NO，播放器内部自行处理相关控制逻辑
 */
@required
/**
 *  @brief              远程控制playCommand
 */
- (BOOL)miguAreaSDKAudioPlayerRemoteControlPlayCommand;

/**
 *  @brief              远程控制pauseCommand
 */
- (BOOL)miguAreaSDKAudioPlayerRemoteControlPauseCommand;

/**
 *  @brief              远程控制togglePlayPauseCommand
 */
- (BOOL)miguAreaSDKAudioPlayerRemoteControlTogglePlayPauseCommand;

/**
 *  @brief              远程控制nextTrackCommand
 */
- (BOOL)miguAreaSDKAudioPlayerRemoteControlNextTrackCommand;

/**
 *  @brief              远程控制previousTrackCommand
 */
- (BOOL)miguAreaSDKAudioPlayerRemoteControlPreviousTrackCommand;

#pragma mark - 播放器相关信息回调
@optional
/**
 *  @brief              播放器状态变更回调
 */
- (void)miguAreaSDKAudioPlayerStatusDidChange:(MiguAreaSDKAudioPlayerStatus)status;

/**
 *  @brief              播放器播放模式变更回调
 */
- (void)miguAreaSDKAudioPlayerModeDidChange:(MiguAreaSDKAudioPlayerMode)playMode;

/**
 *  @brief              播放器播放列表变更回调
 */
- (void)miguAreaSDKAudioPlayerPlayListDidChange:(NSArray *)playList;

/**
 *  @brief              播放器当前时间变更回调
 */
- (void)miguAreaSDKAudioPlayerCurrentTimeDidChange:(NSTimeInterval)currentTime;

/**
 *  @brief              播放器缓冲时长变更回调
 */
- (void)miguAreaSDKAudioPlayerLoadedTimeRangeDidChange:(NSTimeInterval)loadedTimeRange;

/**
 *  @brief              播放器当前音乐变更回调
 */
- (void)miguAreaSDKAudioPlayerCurrentMusicDidChange:(MusicInfo *)musicInfo;

/**
 *  @brief              播放器加载失败回调
 */
- (void)miguAreaSDKAudioPlayerLoadMusicInfoDidFail:(NSError *)error;






@end


@interface MiguAreaSDKAudioPlayer : NSObject

@property (nonatomic, weak) id <MiguAreaSDKAudioPlayerDelegate> delegate;

+ (instancetype)sharedInstance;

#pragma mark - 开始播放
/**
 *  @brief              开始播放接口
 *  @param  playList    播放列表
 *  @param  offset      播放歌曲在播放列表中的位置
 *  @discuss    播放器本身对播放列表做了缓存，若需要按照缓存列表进行播放，请调用resume接口。
 */
- (void)startPlayWithPlayList:(NSArray <MusicInfo *> *)playList
                       offset:(NSInteger)offset;

#pragma mark - 基本信息
/**
 *  @brief              获取和设置播放模式
 *  @param  playMode    播放模式
 */
- (void)setPlayMode:(MiguAreaSDKAudioPlayerMode)playMode;
- (MiguAreaSDKAudioPlayerMode)playMode;

/**
 *  @brief              播放状态
 */
- (MiguAreaSDKAudioPlayerStatus)playerStatus;

/**
 *  @brief              播放列表
 *  @return 返回播放列表数组，数组元素为MusicInfo
 */
- (NSArray *)audioPlayerPlayList;

/**
 *  @brief              当前播放歌曲
 */
- (MusicInfo *)currentMusicInfo;

/**
 *  @brief              播放歌曲总时长
 */
- (NSTimeInterval)playerDuration;

/**
 *  @brief              播放歌曲当前时间
 */
- (NSTimeInterval)playerCurrentTime;

/**
 *  @brief              歌曲缓冲时长
 */
- (NSTimeInterval)playerLoadedTimeRange;

#pragma mark - Play Control

/**
 *  @brief              暂停播放
 */
- (void)pause;

/**
 *  @brief              恢复播放
 *  @discuss            播放器本身对播放列表做了缓存，若需要按照缓存列表进行播放，请调用本接口
 */
- (void)resume;

/**
 *  @brief              停止播放，清空播放器
 */
- (void)stop;

/**
 *  @brief                      播放下一首
 *  @param  ifMoveToNextSong    是否播放列表下一首歌
 *  @discuss    参数ifMoveToNextSong只有在MiguAreaSDKAudioPlayerModeSingleLoop下才会进行校验，在该模式下，若为YES，则播放列表下一首歌曲， 若NO，则播放当前歌曲
 */
- (void)playNext:(BOOL)ifMoveToNextSong;

/**
 *  @brief                      播放上一首
 *  @discuss    参数同播放下一首，若YES，则播放列表上一首歌曲，若NO，则播放当前歌曲
 */
- (void)playPrevious:(BOOL)ifMoveToPreviousSong;

/**
 *  @brief               快进快退
 *  @param  seekTime     快进快退时间点, 单位为秒
 *  @param  completeBlock   完成回调
 *  @discuss    若传入时间大于总时长，将不做任何操作
 */
- (void)seekToTime:(NSTimeInterval)seekTime complete:(void (^)(void))completeBlock;

#pragma mark - 添加、删除歌曲
/**
 *  @brief                      添加歌曲到播放列表
 *  @param  musicInfoArray      待添加歌曲数组
 */
- (void)addNewSongsToPlayList:(NSArray <MusicInfo *> *)musicInfoArray;

/**
 *  @brief                      从播放列表删除歌曲
 *  @param  musicInfoArray      待删除歌曲数组
 *  @discuss    1. 若待删除数组中包含当前播放歌曲，会自动切换到删除后列表的下一首歌。
                2. 若清空播放列表，将调用stop方法停止播放。
 */
- (void)deleteSongsFromPlayList:(NSArray <MusicInfo *> *)musicInfoArray;

#pragma mark - 列表歌曲状态改变
/**
 *  @brief                  播放列表中歌曲状态改变后，调用该接口更新播放列表数据
 *  @param  musicInfoArray  状态改变歌曲数组
 */
- (void)musicStatusChanged:(NSArray <MusicInfo *> *)musicInfoArray;

#pragma mark - 调整音量
/**
 *  @brief                  修改当前音频音量大小
 *  @param  volume          音量大小，数字在0-1之间
 */
- (void)setVolume:(CGFloat)volume;

#pragma mark - 远程控制
/**
 *  @brief                  打开远程控制
 */
- (void)beginReceiveRemoteControl;

/**
 *  @brief                  关闭远程控制
 */
- (void)endReceiveRemoteControl;

/**
 *  @brief                  设置锁屏音乐信息
 *  @param  songImage       锁屏音乐图片
 *  @discuss    由于远程控制添加了进度条拖动功能，因此本SDK外部请勿单独设置锁屏音乐信息，避免出现进度条显示UI错误
 */
- (void)updateNowPlayingInfo:(UIImage *)songImage;



@end


















