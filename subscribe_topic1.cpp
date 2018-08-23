/*subscribe topicの作成*/

#include <ros/ros.h>
#include <serial/serial.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <time.h>
#include <std_msgs/String.h>
#include <motor/control.h>
//#include <sensor_msgs/Joy.h>

// シリアル通信の設定
std::string port0 = "/dev/ttyUSBwheel1";
uint32_t baud = 115200; //setup baud
serial::Serial motor_serial0(port0, baud, serial::Timeout::simpleTimeout(1000));



// subscribeする対象のトピックが更新されたら呼び出されるCallback関数
//引数にはトピックにPublishされるメッセージの型と同じ型を定義する
void motorCallback(const motor::control msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	//char型ポインタを使用しmotorのデータを取得
	char* motor_get_data();
}


int main(int argc, char** argv)
{
	char* data;
	ros::init(argc, argv, "motor_node");  // ノードの初期化
	ros::NodeHandle nh; //ノードのハンドルを宣言
	ros::Rate rate(30.0);


	//SubscriberとしてmotorというトピックがSubscribeし、トピックが更新された時は
	//motorCallbackという名前のCallback関数を実行する
	//購読者Qのサイズは1000(購読者キューには配信者から送信されてくるメッセージが蓄積)
	ros::Subscriber sub = n.subscribe("motor", 1000, motorCallback);

	while(ros::ok())
	{
		// トピックの更新の待ち受けを行うAPI
		ros::spinOnce();
		motor_serial0.read(data);  // データを受信する
		data = motor_get_data();  // 受信したデータを読む
		rate.sleep();
	}
}
//dataを保存するコードを書く必要がある(ros->exel)
