// Auto-generated. Do not edit!

// (in-package arm_gazebo.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ikServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.links = null;
      this.ee = null;
    }
    else {
      if (initObj.hasOwnProperty('links')) {
        this.links = initObj.links
      }
      else {
        this.links = [];
      }
      if (initObj.hasOwnProperty('ee')) {
        this.ee = initObj.ee
      }
      else {
        this.ee = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ikServiceRequest
    // Serialize message field [links]
    bufferOffset = _arraySerializer.float32(obj.links, buffer, bufferOffset, null);
    // Serialize message field [ee]
    bufferOffset = _arraySerializer.float32(obj.ee, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ikServiceRequest
    let len;
    let data = new ikServiceRequest(null);
    // Deserialize message field [links]
    data.links = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [ee]
    data.ee = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.links.length;
    length += 4 * object.ee.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'arm_gazebo/ikServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c3a398fe782f9e2bda9eafa35909ec68';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[] links
    float32[] ee
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ikServiceRequest(null);
    if (msg.links !== undefined) {
      resolved.links = msg.links;
    }
    else {
      resolved.links = []
    }

    if (msg.ee !== undefined) {
      resolved.ee = msg.ee;
    }
    else {
      resolved.ee = []
    }

    return resolved;
    }
};

class ikServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angles = null;
    }
    else {
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ikServiceResponse
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.float64(obj.angles, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ikServiceResponse
    let len;
    let data = new ikServiceResponse(null);
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.angles.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'arm_gazebo/ikServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b7ca77b9da2dfe623a276e10b570d2df';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] angles
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ikServiceResponse(null);
    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
    }

    return resolved;
    }
};

module.exports = {
  Request: ikServiceRequest,
  Response: ikServiceResponse,
  md5sum() { return '739e17d373aedcc76ba2f276406c2579'; },
  datatype() { return 'arm_gazebo/ikService'; }
};
