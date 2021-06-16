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

class fkServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angles = null;
      this.links = null;
    }
    else {
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
      }
      if (initObj.hasOwnProperty('links')) {
        this.links = initObj.links
      }
      else {
        this.links = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type fkServiceRequest
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.float64(obj.angles, buffer, bufferOffset, null);
    // Serialize message field [links]
    bufferOffset = _arraySerializer.float64(obj.links, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type fkServiceRequest
    let len;
    let data = new fkServiceRequest(null);
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [links]
    data.links = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.angles.length;
    length += 8 * object.links.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'arm_gazebo/fkServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ea15aaceb74bd9e7419424c414492313';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] angles
    float64[] links
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new fkServiceRequest(null);
    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
    }

    if (msg.links !== undefined) {
      resolved.links = msg.links;
    }
    else {
      resolved.links = []
    }

    return resolved;
    }
};

class fkServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ee = null;
    }
    else {
      if (initObj.hasOwnProperty('ee')) {
        this.ee = initObj.ee
      }
      else {
        this.ee = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type fkServiceResponse
    // Serialize message field [ee]
    bufferOffset = _arraySerializer.float64(obj.ee, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type fkServiceResponse
    let len;
    let data = new fkServiceResponse(null);
    // Deserialize message field [ee]
    data.ee = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.ee.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'arm_gazebo/fkServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '65babecddad448c19eadaa319f462d2d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] ee
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new fkServiceResponse(null);
    if (msg.ee !== undefined) {
      resolved.ee = msg.ee;
    }
    else {
      resolved.ee = []
    }

    return resolved;
    }
};

module.exports = {
  Request: fkServiceRequest,
  Response: fkServiceResponse,
  md5sum() { return '7064256d7c8bd8994ec62c2cfe279a6e'; },
  datatype() { return 'arm_gazebo/fkService'; }
};
