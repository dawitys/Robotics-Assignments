// Auto-generated. Do not edit!

// (in-package arm_gazebo.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Angles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.base_hinge = null;
      this.arm1_hinge = null;
      this.arm2_hinge = null;
      this.arm3_hinge = null;
    }
    else {
      if (initObj.hasOwnProperty('base_hinge')) {
        this.base_hinge = initObj.base_hinge
      }
      else {
        this.base_hinge = 0.0;
      }
      if (initObj.hasOwnProperty('arm1_hinge')) {
        this.arm1_hinge = initObj.arm1_hinge
      }
      else {
        this.arm1_hinge = 0.0;
      }
      if (initObj.hasOwnProperty('arm2_hinge')) {
        this.arm2_hinge = initObj.arm2_hinge
      }
      else {
        this.arm2_hinge = 0.0;
      }
      if (initObj.hasOwnProperty('arm3_hinge')) {
        this.arm3_hinge = initObj.arm3_hinge
      }
      else {
        this.arm3_hinge = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Angles
    // Serialize message field [base_hinge]
    bufferOffset = _serializer.float32(obj.base_hinge, buffer, bufferOffset);
    // Serialize message field [arm1_hinge]
    bufferOffset = _serializer.float32(obj.arm1_hinge, buffer, bufferOffset);
    // Serialize message field [arm2_hinge]
    bufferOffset = _serializer.float32(obj.arm2_hinge, buffer, bufferOffset);
    // Serialize message field [arm3_hinge]
    bufferOffset = _serializer.float32(obj.arm3_hinge, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Angles
    let len;
    let data = new Angles(null);
    // Deserialize message field [base_hinge]
    data.base_hinge = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm1_hinge]
    data.arm1_hinge = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm2_hinge]
    data.arm2_hinge = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm3_hinge]
    data.arm3_hinge = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arm_gazebo/Angles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ebea2e1e660d8f6f3597c7be6738767c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 base_hinge
    float32 arm1_hinge
    float32 arm2_hinge
    float32 arm3_hinge
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Angles(null);
    if (msg.base_hinge !== undefined) {
      resolved.base_hinge = msg.base_hinge;
    }
    else {
      resolved.base_hinge = 0.0
    }

    if (msg.arm1_hinge !== undefined) {
      resolved.arm1_hinge = msg.arm1_hinge;
    }
    else {
      resolved.arm1_hinge = 0.0
    }

    if (msg.arm2_hinge !== undefined) {
      resolved.arm2_hinge = msg.arm2_hinge;
    }
    else {
      resolved.arm2_hinge = 0.0
    }

    if (msg.arm3_hinge !== undefined) {
      resolved.arm3_hinge = msg.arm3_hinge;
    }
    else {
      resolved.arm3_hinge = 0.0
    }

    return resolved;
    }
};

module.exports = Angles;
