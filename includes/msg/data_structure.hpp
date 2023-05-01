/// ******************************************************************
/// \copyright Copyright(C) 2022-2032 YTKC \n
/// All rights reserved.
///
/// \brief 数据结构
/// \details 定义故障诊断组件所需要的数据结构
///
/// \verbatim
/// 序的变更记录：
/// 2022-05-13，周东风
/// -创建第一版程序
/// \endverbatim
/// ******************************************************************

#ifndef __DATA_STRUCTURE_H__
#define __DATA_STRUCTURE_H__

#include <string>
#include <stdint.h>
#include <vector>

namespace yutong{
namespace diagnosis {

    typedef enum{
        GEAR_STATUS_N = 1,           //N档
        GEAR_STATUS_D = 2,           //D档
        GEAR_STATUS_R = 3,           //R档
        GEAR_STATUS_L = 4,           //L档
    }GearStatus_t;

    typedef enum{
        DRIVE_MODE_AUTO = 1,          //自动驾驶
        DRIVE_MODE_MANUAL = 2,        //人工驾驶
        DRIVE_MODE_ASSISTANT = 3,     //辅助驾驶
        DRIVE_MODE_LOCAL = 4,         //本地遥控
        DRIVE_MODE_REMOTE = 5         //远程驾驶
    }DriveMode_t;

    typedef enum{
        VCU_DRIVE_MODE_AUTO = 1,       //自动驾驶
        VCU_DRIVE_MODE_MANUAL = 2,     //人工驾驶
        VCU_DRIVE_MODE_ASSISTANT = 3,  //辅助驾驶
        VCU_DRIVE_MODE_LOCAL = 4,      //本地遥控
        VCU_DRIVE_MODE_REMOTE = 5      //远程驾驶
    }VcuDriveMode_t;

    typedef enum{
        STEERING_MODE_AUTO = 1,        //人工驾驶
        STEERING_MODE_MANUAL = 2       //自动驾驶
    }SterringMode_t;

    typedef enum{
        LIGHT_STATUS_CLOSE = 1,        //关闭
        LIGHT_STATUS_OPEN = 2          //打开
    }LightStatus_t;

    typedef enum{
        TIPPER_STATUS_NONE = 1,         //无举升
        TIPPER_STATUS_UP = 2,           //举升过程中
        TIPPER_STATUS_TOP = 3,          //举升到顶
        TIPPER_STATUS_DOWN = 4,         //下降过程中
        TIPPER_STATUS_STOP = 5          //停止
    }TipperStatus_t;

    typedef enum{
        EPB_STATUS_UP = 1,               //释放
        EPB_STATUS_DOWN = 2              //拉起
    }EpbStatus_t;

    typedef enum{
        DOOR_STATUS_CLOSE = 1,          //关闭
        DOOR_STATUS_OPEN = 2            //打开
    }DoorStatus_t;

    typedef enum
    {
        MOTOR_DIRECTION_FORWARD = 1,   //正转
        MOTOR_DIRECTION_REVERSAL = 2   //反转
    }MotorDirection_t;


    typedef enum{
        GEAR_CMD_N = 1,               //N档
        GEAR_CMD_D = 2,               //D档
        GEAR_CMD_R = 3,               //R档
        GEAR_CMD_L = 4                //L档
    }GearCmd_t;

    typedef enum{
        LIGHT_CMD_CLOSE = 1,         //关闭
        LIGHT_CMD_OPEN = 2           //打开
    }LightCmd_t;

    typedef enum{
        TIPPER_CMD_UP = 1,           //举升
        TIPPER_CMD_STOP = 2,         //停止
        TIPPER_CMD_DOWN = 3          //下降
    }TripperCmd_t;

    typedef enum{
        EPB_CMD_UP = 1,              //释放
        EPB_CMD_DOWN = 2             //拉起
    }EpbCmd_t;

    typedef enum{
        DOOR_CMD_CLOSE = 1,          //关闭
        DOOR_CMD_OPEN = 2            //打开
    }DoorCmd_t;
    
    typedef enum{
        DRIVE_FLAG_UNABLE = 1,       //驱动不激活
        DRIVE_FLAG_ENABLE = 2        //驱动激活
    }DriveFlagCmd_t;

    typedef enum{
        BRAKE_FLAG_UNABLE = 1,       //制动不激活
        BRAKE_FLAG_ENABLE = 2        //制动激活
    }BrakeFlagCmd_t;


    struct Point3D{
        double   x;
        double   y;
        double   z;
    };

    struct TrajectoryPoint{
        Point3D  pos;   
        double   target_speed;              //目标车速                      
    };

    typedef struct ChassisInfo{
        uint32_t auto_mode;                  //车辆驾驶模式
        uint32_t vcu_dirve_mode;             //vcu驾驶模式
        double   real_speed;                 //车速
        uint32_t vcu_gear;                   //vcu反馈档位
        double   steering_wheel_angle;       //方向盘反馈转角
        uint32_t steering_wheel_mode;        //转向反馈模式
        uint32_t epb_status;                 //epb状态
        double   vcu_throttle_opening;       //vcu响应油门开度
    }ChassisInfo_t;
    
    typedef struct ChassisAuxiliaryInfo{
        uint32_t left_light_status;          //左转灯状态
        uint32_t right_light_status;         //右转灯状态
        uint32_t low_light_status;           //近光灯状态
        uint32_t high_light_status;          //远光灯状态
        uint32_t double_flash_light_status;  //双闪灯状态
        double   longitudinal_acc;           //纵向加速度
        double   feedback_curvature;         //反馈曲率
        uint32_t left_door1_status;          //左门1状态
        uint32_t left_door2_status;          //左门2状态
        uint32_t left_door3_status;          //左门3状态
        uint32_t left_door4_status;          //左门4状态
        uint32_t right_door1_status;         //右门1状态
        uint32_t right_door2_status;         //右门2状态
        uint32_t right_door3_status;         //右门3状态
        uint32_t right_door4_status;         //右门4状态
        double   left_front_wheel_speed;     //左前轮速
        double   right_front_wheel_speed;    //右前轮速
        double   left_rear_wheel_speed;      //左后轮速
        double   right_rear_wheel_speed;     //右后轮速
    }ChassisAuxiliaryInfo_t;

    typedef struct TruckChassisInfo{
        uint32_t tipper_status;              //翻斗状态
    }TruckChassisInfo_t;

    typedef struct ControlInfo{
        uint32_t steering_wheel_mode_cmd;    //转向控制模式 
        double   steering_wheel_angle_cmd;   //方向盘控制转角
        double   steering_wheel_speed_cmd;   //方向盘控制转角速率
        uint32_t drive_activation_flag_cmd;  //驱动激活标识
        double   throttle_opening_cmd;       //控制油门开度
        uint32_t brake_status_flag_cmd;      //制动激活标识
        double   brake_deceleration_cmd;     //控制制动减速度
        uint32_t epb_cmd;                    //控制epb
        uint32_t gear_cmd;                   //控制档位
    }ControlInfo_t;

    typedef struct ControlAuxiliaryInfo{
        uint32_t left_light_cmd;             //控制左转灯
        uint32_t right_light_cmd;            //控制右转灯
        uint32_t low_light_cmd;              //控制近光灯
        uint32_t high_light_cmd;             //控制远光灯
        uint32_t double_flash_light_cmd;     //控制双闪灯
        double   target_curvature_flag_cmd;  //目标曲率标识
        double   target_curvature_cmd;       //目标曲率
        uint32_t left_door1_cmd;             //控制左门1
        uint32_t left_door2_cmd;             //控制左门2
        uint32_t left_door3_cmd;             //控制左门3
        uint32_t left_door4_cmd;             //控制左门4
        uint32_t right_door1_cmd;            //控制右门1
        uint32_t right_door2_cmd;            //控制右门2
        uint32_t right_door3_cmd;            //控制右门3
        uint32_t right_door4_cmd;            //控制右门4
    }ControlAuxiliaryInfo_t;

    typedef struct TruckControlInfo{
        uint32_t tipper_cmd;                 //控制翻斗
    }

    typedef struct LocationInfo{
        double   longitude;                  //经度
        double   latitude;                   //纬度
    }LocationInfo_t;
    
    typedef struct TrajectoryInfo{
       std::vector<TrajectoryPoint> trajs;   //轨迹信息
    }TrajectoryInfo_t;

}
}


#endif