/*
 * Models wrapping the gateway API
 */

#ifndef _models_h_
#define _models_h_

#include <stdint.h>

enum GATEWAY_OPCODE {
	OP_DISPATCH,              /* client <-  server */
	OP_HEARTBEAT,             /* client <-> server */
	OP_IDENTIFY,              /* client  -> server */
	OP_STATUS_UPDATE,         /* client  -> server */
	OP_VOICE_STATE_UPDATE,    /* client  -> server */
	OP_VOICE_SERVER_PING,     /* client  -> server */
	OP_RESUME,                /* client  -> server */
	OP_RECONNECT,             /* client <-  server */
	OP_REQUEST_GUILD_MEMBERS, /* client  -> server */
	OP_INAVLID_SESSION,       /* client <-  server */
	OP_HELLO,                 /* client <-  server */
	OP_HEARTBEAT_ACK,         /* client <-  server */

	GATEWAY_OPCODE_COUNT
};

enum DISPATCH_TYPE {
	DISPATCH_READY,
	DISPATCH_RESUMED,

	DISPATCH_GUILD_CREATE,
	DISPATCH_GUILD_UPDATE,
	DISPATCH_GUILD_EMOJIS_UPDATE,
	DISPATCH_GUILD_INTEGRATIONS_UPDATE,
	DISPATCH_GUILD_SYNC,
	DISPATCH_GUILD_DELETE,

	DISPATCH_GUILD_MEMBER_ADD,
	DISPATCH_GUILD_MEMBER_UPDATE,
	DISPATCH_GUILD_MEMBER_REMOVE,
	DISPATCH_GUILD_MEMBERS_CHUNK,

	DISPATCH_GUILD_ROLE_CREATE,
	DISPATCH_GUILD_ROLE_UPDATE,
	DISPATCH_GUILD_ROLE_DELETE,

	DISPATCH_GUILD_BAN_ADD,
	DISPATCH_GUILD_BAN_REMOVE,

	DISPATCH_CHANNEL_CREATE,
	DISPATCH_CHANNEL_UPDATE,
	DISPATCH_CHANNEL_DELETE,

	DISPATCH_CHANNEL_PINS_ACK, /* client */
	DISPATCH_CHANNEL_PINS_UPDATE, /* client */

	DISPATCH_CHANNEL_RECIPIENT_ADD,
	DISPATCH_CHANNEL_RECIPIENT_REMOVE,

	DISPATCH_MESSAGE_CREATE,
	DISPATCH_MESSAGE_UPDATE,
	DISPATCH_MESSAGE_DELETE,
	DISPATCH_MESSAGE_DELETE_BULK,

	DISPATCH_MESSAGE_ACK, /* client */

	DISPATCH_PRESENCE_UPDATE,

	DISPATCH_TYPING_START,

	DISPATCH_USER_UPDATE,

	DISPATCH_USER_SETTINGS_UPDATE, /* client */

	DISPATCH_VOICE_STATE_UPDATE,
	DISPATCH_VOICE_SERVER_UPDATE,

	DISPATCH_TYPE_COUNT
};

/* op 0 is handled specially (see above enum) */

/*
 * op: 1 (HEARTBEAT)
 */
struct model_heartbeat {
	uint32_t sequence;
};

/*
 * op: 2 (IDENTIFY)
 */
struct model_identify {
	char* token;

	/* properties */
	char* os;
	char* browser;
	char* device;
	char* referrer;
	char* referring_domain;

	uint8_t compress;
	uint8_t threshold;

	uint32_t shard_id;
	uint32_t shard_count;
};

/*
 * op: 10 (HELLO)
 */
struct model_hello {
	uint32_t heartbeat_interval;
	size_t gateway_server_count;
	char** gateway_servers;
};

#endif /* _models_h_ */