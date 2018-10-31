import {SELECT_LOG, LOAD_LOGS_SUCCESS} from '../constants';
const initialState={};
export default function selectedLog(state = initialState, action) {
    switch (action.type) {
      case LOAD_LOGS_SUCCESS:
        return {...action.payload.messages};
      default:
        return state
    }
  }