import {SELECT_LOG} from '../constants';
const initialState={
    selectedLog: -1
}
export default function selectedLog(state = initialState, action) {
    switch (action.type) {
      case SELECT_LOG:
        return {selectedLog: action.payload};
      default:
        return state
    }
  }