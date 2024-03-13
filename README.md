# mssg
Задача
const uint32_t COMMON_HEADER_SIZE     = 1;

const uint32_t SETUP_REQUEST_MSG_SIZE   = 7;

const uint16_t SETUP_REQUEST_MSG_ID   = 16;

void init_setup_request_msg(uint8_t *setup_request_mgs_p,

uint8_t role_id,

uint32_t session_id)

{

// сформируйте сообщение по данному шаблону в сетевом порядке:

// [header:1(SETUP_REQUEST_MSG_ID)][msg_size:2][role_id][seesion_id]

}

int main()

{

uint8_t setup_msg[COMMON_HEADER_SIZE+SETUP_REQUEST_MSG_SIZE];

init_setup_request_msg(setup_msg, 10, 100);

}
