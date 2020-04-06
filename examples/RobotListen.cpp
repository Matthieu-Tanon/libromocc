#include <iostream>
#include <chrono>
#include <thread>

#include "romocc/Robot.h"

using namespace romocc;

int main(int argc, char *argv[])
{
    auto print_message = []()
    {
        std::cout << "State updated" << "\n";
    };

    auto ur5 = Robot::New();
    ur5->configure(Manipulator(), "192.168.153.131", 30003);

    if(ur5->connect())
    {
        ur5->addUpdateSubscription(print_message);

        auto initialJointConfig = ur5->getCurrentState()->getJointConfig();
        std::cout << initialJointConfig.transpose() << std::endl;

        double previousTime = 0;
        bool stop = false;
        std::thread processing_thread([&](){
            while(!stop){
                Vector6d jointConfig = ur5->getCurrentState()->getJointConfig();
                double currentTime = ur5->getCurrentState()->getTimestamp();
                Transform3d m_bM1 = ur5->getCurrentState()->getTransformToJoint(1);
                Transform3d m_bM2 = ur5->getCurrentState()->getTransformToJoint(2);
                Transform3d m_bM3 = ur5->getCurrentState()->getTransformToJoint(3);
                Transform3d m_bM4 = ur5->getCurrentState()->getTransformToJoint(4);
                Transform3d m_bM5 = ur5->getCurrentState()->getTransformToJoint(5);
                Transform3d m_bM6 = ur5->getCurrentState()->getTransformToJoint(6);

                if(currentTime > previousTime)
                {
                    std::cout << jointConfig.transpose() << std::endl;
                    previousTime = ur5->getCurrentState()->getTimestamp();
                }
            }
        });

        std::this_thread::sleep_for(std::chrono::seconds(1));
        stop = true;
        processing_thread.join();
    }


}