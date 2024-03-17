#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <thread>

class DroneControl : public rclcpp::Node
{
public:
    DroneControl()
        : Node("drone_control_cpp")
    {
        cmd_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    }

    void takeoff_hover_land()
    {
        auto cmd_msg = std::make_shared<geometry_msgs::msg::Twist>();

        // Commanding the drone to take off
        cmd_msg->linear.z = 1.0;
        cmd_pub_->publish(*cmd_msg);
        RCLCPP_INFO(this->get_logger(), "Taking off...");
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 5 seconds for the drone to take off

        // Commanding the drone to hover
        cmd_msg->linear.z = 0.0;
        cmd_pub_->publish(*cmd_msg);
        RCLCPP_INFO(this->get_logger(), "Hovering...");
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Hover for 5 seconds

        // Commanding the drone to land
        cmd_msg->linear.z = -1.0;
        cmd_pub_->publish(*cmd_msg);
        RCLCPP_INFO(this->get_logger(), "Landing...");
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 5 seconds for the drone to land
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto drone_control_node = std::make_shared<DroneControl>();
    drone_control_node->takeoff_hover_land();
    rclcpp::shutdown();
    return 0;
}
