#pragma once
// MESSAGE MONITORING PACKING

#define MAVLINK_MSG_ID_MONITORING 180


typedef struct __mavlink_monitoring_t {
 uint32_t count; /*<   count.*/
 uint8_t status; /*<   status.*/
} mavlink_monitoring_t;

#define MAVLINK_MSG_ID_MONITORING_LEN 5
#define MAVLINK_MSG_ID_MONITORING_MIN_LEN 5
#define MAVLINK_MSG_ID_180_LEN 5
#define MAVLINK_MSG_ID_180_MIN_LEN 5

#define MAVLINK_MSG_ID_MONITORING_CRC 82
#define MAVLINK_MSG_ID_180_CRC 82



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MONITORING { \
    180, \
    "MONITORING", \
    2, \
    {  { "count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_monitoring_t, count) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_monitoring_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MONITORING { \
    "MONITORING", \
    2, \
    {  { "count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_monitoring_t, count) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_monitoring_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a monitoring message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param count   count.
 * @param status   status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_monitoring_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t count, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MONITORING_LEN];
    _mav_put_uint32_t(buf, 0, count);
    _mav_put_uint8_t(buf, 4, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MONITORING_LEN);
#else
    mavlink_monitoring_t packet;
    packet.count = count;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MONITORING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MONITORING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
}

/**
 * @brief Pack a monitoring message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param count   count.
 * @param status   status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_monitoring_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t count,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MONITORING_LEN];
    _mav_put_uint32_t(buf, 0, count);
    _mav_put_uint8_t(buf, 4, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MONITORING_LEN);
#else
    mavlink_monitoring_t packet;
    packet.count = count;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MONITORING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MONITORING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
}

/**
 * @brief Encode a monitoring struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param monitoring C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_monitoring_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_monitoring_t* monitoring)
{
    return mavlink_msg_monitoring_pack(system_id, component_id, msg, monitoring->count, monitoring->status);
}

/**
 * @brief Encode a monitoring struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param monitoring C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_monitoring_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_monitoring_t* monitoring)
{
    return mavlink_msg_monitoring_pack_chan(system_id, component_id, chan, msg, monitoring->count, monitoring->status);
}

/**
 * @brief Send a monitoring message
 * @param chan MAVLink channel to send the message
 *
 * @param count   count.
 * @param status   status.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_monitoring_send(mavlink_channel_t chan, uint32_t count, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MONITORING_LEN];
    _mav_put_uint32_t(buf, 0, count);
    _mav_put_uint8_t(buf, 4, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MONITORING, buf, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
#else
    mavlink_monitoring_t packet;
    packet.count = count;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MONITORING, (const char *)&packet, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
#endif
}

/**
 * @brief Send a monitoring message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_monitoring_send_struct(mavlink_channel_t chan, const mavlink_monitoring_t* monitoring)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_monitoring_send(chan, monitoring->count, monitoring->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MONITORING, (const char *)monitoring, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
#endif
}

#if MAVLINK_MSG_ID_MONITORING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_monitoring_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t count, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, count);
    _mav_put_uint8_t(buf, 4, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MONITORING, buf, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
#else
    mavlink_monitoring_t *packet = (mavlink_monitoring_t *)msgbuf;
    packet->count = count;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MONITORING, (const char *)packet, MAVLINK_MSG_ID_MONITORING_MIN_LEN, MAVLINK_MSG_ID_MONITORING_LEN, MAVLINK_MSG_ID_MONITORING_CRC);
#endif
}
#endif

#endif

// MESSAGE MONITORING UNPACKING


/**
 * @brief Get field count from monitoring message
 *
 * @return   count.
 */
static inline uint32_t mavlink_msg_monitoring_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field status from monitoring message
 *
 * @return   status.
 */
static inline uint8_t mavlink_msg_monitoring_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a monitoring message into a struct
 *
 * @param msg The message to decode
 * @param monitoring C-struct to decode the message contents into
 */
static inline void mavlink_msg_monitoring_decode(const mavlink_message_t* msg, mavlink_monitoring_t* monitoring)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    monitoring->count = mavlink_msg_monitoring_get_count(msg);
    monitoring->status = mavlink_msg_monitoring_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MONITORING_LEN? msg->len : MAVLINK_MSG_ID_MONITORING_LEN;
        memset(monitoring, 0, MAVLINK_MSG_ID_MONITORING_LEN);
    memcpy(monitoring, _MAV_PAYLOAD(msg), len);
#endif
}
