import React, { Component } from 'react';
import Collapse from '@material-ui/core/Collapse';
import { connect } from 'react-redux';
import {selectLog} from '../actions/LogActions';
import ChildLogEntry from './ChildLogEntry';

class ChildLogEntryContainer extends Component {
    styles = {
    }
  renderChildEntries = () => {
    return this.props.responses.map((el)=>{
        return  <ChildLogEntry sender={el.sender}  time={el.timestamp} guid={el.guid}/>
    });   
  }
  isExpanded = () => {
    return this.props.expandedLogs.includes(this.props.parentguid);
  }
  render() {
    return (
        <Collapse in={this.isExpanded()}>
            {this.renderChildEntries()}
        </Collapse>
    );
  }
}
const mapStateToProps = store =>{
    return {
        selectedLog: store.selectedLog.selectedLog,
        expandedLogs: store.selectedLog.expandedLogs,
    };
}
export default connect(mapStateToProps, {selectLog})(ChildLogEntryContainer);
