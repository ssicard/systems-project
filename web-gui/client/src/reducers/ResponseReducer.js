import { INITIALIZE_RESPONSES } from "../constants/index";

const initialState=[];
export default function responses(state = initialState, action) {
    switch (action.type) {
      case INITIALIZE_RESPONSES:
        return action.payload;
      default:
        return state
    }
  }