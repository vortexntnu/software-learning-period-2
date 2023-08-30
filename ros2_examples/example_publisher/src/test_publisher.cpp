#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <example_msgs/msg/sphere.hpp>

class test_publisher : public rclcpp::Node
{
public:
    test_publisher()
    : Node("test_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("test_string_topic", 10);
        timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500), std::bind(&test_publisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        // Test string publisher
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: " << message.data);
        publisher_->publish(message);

        // Test sphere publisher
        auto sphere_message = example_msgs::msg::Sphere();
        sphere_message.radius = 1.0;
        sphere_message.center.x = 0.0;
        sphere_message.center.y = 0.0;
        sphere_message.center.z = 0.0;
        sphere_publisher_->publish(sphere_message);
        
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Publisher<example_msgs::msg::Sphere>::SharedPtr sphere_publisher_;
    size_t count_ = 1;


};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<test_publisher>());
    rclcpp::shutdown();
    return 0;
}