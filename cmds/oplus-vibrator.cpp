#include <iostream>
#include <unistd.h>
#include <vendor/oplus/hardware/lmvibrator/1.0/ILinearMotorVibrator.h>

using ::vendor::oplus::hardware::lmvibrator::V1_0::ILinearMotorVibrator;
using ::android::sp;

int main(int argc, char **argv) {
	auto svc = ILinearMotorVibrator::getService();
	if(svc == nullptr) {
		std::cerr << "Failed getting ILinearMotorVibrator" << std::endl;
		return -1;
	}
	if(argc<2) {
		std::cerr << "Usage: " << argv[0] << " <on|off>" << std::endl;
		return -1;
	}
	std::string cmd(argv[1]);
	if(cmd == "on_rtp") {
		if(argc!=4) {
			std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <waveform_id> <amplitude>" << std::endl;
			return -1;
		}
		svc->linearmotorVibratorOn(atoi(argv[2]), atoi(argv[3]), true);
	} else if(cmd == "on") {
		if(argc!=4) {
			std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <waveform_id> <amplitude>" << std::endl;
			return -1;
		}
		svc->linearmotorVibratorOn(atoi(argv[2]), atoi(argv[3]), false);
	} else if(cmd == "off") {
		svc->linearmotorVibratorOff();
	}
}
