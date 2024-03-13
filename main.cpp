#include <iostream>
#include <cstdint>

const uint32_t COMMON_HEADER_SIZE = 1;
const uint32_t SETUP_REQUEST_MSG_SIZE = 7;
const uint16_t SETUP_REQUEST_MSG_ID = 16;

void init_setup_request_msg(uint8_t *setup_request_mgs_p, uint8_t role_id, uint32_t session_id) {
    if (setup_request_mgs_p == nullptr) {
        std::cerr << "Ошибка: недопустимый указатель на массив" << std::endl;
        return;
    }

    setup_request_mgs_p[0] = SETUP_REQUEST_MSG_ID; 
    setup_request_mgs_p[1] = SETUP_REQUEST_MSG_SIZE >> 8; 
    setup_request_mgs_p[2] = SETUP_REQUEST_MSG_SIZE & 0xFF; 
    setup_request_mgs_p[3] = role_id; 
    setup_request_mgs_p[4] = (session_id >> 24) & 0xFF; 
    setup_request_mgs_p[5] = (session_id >> 16) & 0xFF;
    setup_request_mgs_p[6] = (session_id >> 8) & 0xFF;
    setup_request_mgs_p[7] = session_id & 0xFF; 
}

int main() {
    uint8_t setup_msg[COMMON_HEADER_SIZE + SETUP_REQUEST_MSG_SIZE];

    init_setup_request_msg(setup_msg, 10, 100);

    for (int i = 0; i < COMMON_HEADER_SIZE + SETUP_REQUEST_MSG_SIZE; ++i) {
        std::cout << std::hex << static_cast<int>(setup_msg[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}
