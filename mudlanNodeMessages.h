#include <iostream>

enum nodeType {
    solitaryNode,
    peerGroupMessage,
    peerGroupLeader
};

enum solitaryNodeMessageType {
    discoverJoinRequestMessage,
    discoverJoinResponseMessage,
    discoverJoinConfirmationMessage
};

enum peerGroupMessageType{
      forwardedRequestMessage,
      responseTriggerMessage,
      txStatusMessage,
      forwardedConfirmationMessage,
      topologyUpdateMessage,
      linkStatusMessage
};

#define MAX_MSG_FIELDS 255
#define DISCOVER_JOIN_MESSAGE_PACKET_WORD_SIZE 36
#define NUM_BYTES_PER_WORD 4
#define DISCOVER_JOIN_MESSAGE_MAX_FIELDS_PER_ROW 10

/* Table XX|| CDL Specification */
unsigned char discoveryJoinMessageTable[][3] = {   
    {0,0,15}, /*  RESERVED BYTES */
    {0,16,23}, /* Version Number */
    {0,24,31}, /* Message Type */
    {1,0,31}, /* Requesting Node ID */
    {2,0,31}, /* Requesting Node Network ID */
    {3,0,31}, /* Target Node ID */
    {4,0,7}, /* Network Node Count */
    {4,8,15}, /* Node Priority */
    {4,16,31}, /* Mission ID */
    {5,0,3}, /* Ant ID 2 */
    {5,4,7}, /* Link ID2 */
    {5,8,11}, /* Ant ID1 */
    {5,12,15}, /* Link ID 1 */
    {5,16,19}, /* Num links */
    {5,20,23}, /* Req Type */
    {5,24,27}, /* Cfg TxBand */
    {5,28,31},  /* Req TxBand*/
    {6,0,15}, /* Platform Type */
    {6,16,23}, /* Discovery Antenna GT */
    {6,24,30}, /* REserved */
    {6,31,31}, /* FB */
    {7,0,15}, /* Transmit Band Lower Edge */
    {7,16,31}, /* Transmit Bandwidth */ 
    {8,0,15}, /* Receive Band Lower Edge */
    {8,16,31}, /* Receive Bandwidth */ 
    {9,0,31}, /* Latitude */
    {10,0,31}, /* Longitude */
    {11,0,15}, /* Heading */ 
    {11,16,31}, /* Altitude */
    {12,0,15}, /* Roll */
    {12,16,31}, /* Pitch */
    {13,0,15}, /* Velocity North */
    {13,16,31}, /* Velocity East */
    {14,0,15}, /* Reserved */
    {14,16,31}, /* Velocity up */
    {15,0,31}, /* TimeStamp */
    {16,0,7}, /* Antenna Type */
    {16,8,15}, /* GT for Band 1 */
    {16,16,23}, /* EIRP for Band 1 */
    {16,24,31}, /* Supported Band 1 */
    {17,0,7}, /* Antenna Location */
    {17,8,15}, /* GT for band 2 */
    {17,16,23}, /* EIRP for band 2 */
    {17,24,31}, /* Supported Band 1 */
    {18,0,15}, /* Antenna Beam Width */
    {18,16,31}, /* Reserved */
    {19,0,1}, /* WF4 */
    {19,2,3}, /* WF3 */
    {19,4,5}, /* WF2 */
    {19,6,7}, /* WF1 */
	{19,8,15}, /* Reserved */
	{19,16,23}, /* Framing Formats */
	{19,24,31}, /* Reserved */
    {20,0,31}, /* Waveform Code 1 */
    {21,0,31}, /* Waveform Code 2 */
    {22,0,31}, /* Waveform Code 3 */
    {23,0,31}, /* Waveform Code 4 */
    {24,0,7}, /* Antenna Type */
    {24,8,15}, /* GT for Band 1 */
    {24,16,23}, /* EIRP for Band 1 */
    {24,24,31}, /* Supported Band 1 */
    {25,0,7}, /* Antenna Location */
    {25,8,15}, /* GT for band 2 */
    {25,16,23}, /* EIRP for band 2 */
    {25,24,31}, /* Supported Band 1 */
    {26, 0, 15}, /* Antenna Beam Width */
    {26,16,31}, /* Reserved */
    {27,0,1}, /* WF4 */
    {27,2,3}, /* WF3 */
    {27,4,5}, /* WF2 */
    {27,6,7}, /* WF1 */
	{27,8,15}, /* Reserved */
	{27,16,23}, /* Framing Formats */
	{27,24,31}, /* Reserved */
    {28,0,31}, /* Waveform Code 1 */
    {29,0,31}, /* Waveform Code 2 */
    {30,0,31}, /* Waveform Code 3 */
    {31,0,31}, /* Waveform Code 4 */
    {32,0,31}, /* Reserved */
    {33,0,31}, /* Reserved */
    {34,0,31}, /* Reserved */
    {35,0,31} /* Reseerved */
};

enum djrMsgRequestInfoMessageType {
	mTypeInvalid,
	mTypeRequestMessage,
	mTypeResponseMessage,
	mTypeConfirmationMessage,
	reserved
};

enum djrMsgVersionNumber {
	version_0,
	version_1,
	reserved
}; 


