import React, { Component } from 'react';
import Paper from '@material-ui/core/Paper';
import ArrowIcon from '@material-ui/icons/ArrowRightAlt';
import CaratIcon from '@material-ui/icons/KeyboardArrowDown';
import Collapse from '@material-ui/core/Collapse';
import { connect } from 'react-redux';
import {selectLog} from '../actions/LogActions';
import ParentLogEntry from './ParentLogEntry';
import ChildLogEntryContainer from './ChildLogEntryContainer';

class LogEntry extends Component {
    styles = {
        entryInnerContainer: {
            display: "flex",
            padding:"5px",
            flexDirection:"row",
            flex:1,
        },
        entryDataLeftCell: {
            flex:2,
            paddingLeft: "10px",
            paddingRight: "10px",
            borderRight: "2px solid black",
            borderColor: "#85aef2",
            borderRadius: "2px",
            flexDirection: 'row',
            display:'flex'

        },
        entryDataMiddleCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
            flex: 4,
        },
        entryDataRightCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
        },
        label: {
            paddingBottom:'2px',
            color: '#AAAAAA',
            fontSize: '13px',
        },
        sourceDestContainer:{
            flex:2,
            display: 'flex',
            flexDirection: 'row',
            alignItems: 'center',
            justifyContent: 'center',
        },
        attribContainer:{
            alignItems: "center",
            flexDirection: 'column',
        }
    }
  getEntryContainerStyle = () =>{
      console.log("Selected Log: "+this.props.selectedLog+"  GUID: "+this.props.guid);
      if(this.props.selectedLog==this.props.guid){
          return {marginBottom:'5px', border: '2px solid red', flexDirection: 'column', display:'flex'};
      } else {
          return {marginBottom: '5px',flexDirection: 'column', display:'flex'};
      }
  }
  getLeftCellStyle = () => {
    if(this.props.selectedLog == this.props.guid){
        return {...this.styles.entryDataLeftCell, borderColor:'red'};
    } else {
        return this.styles.entryDataLeftCell;
    }
  }
  getArrowIconStyle =()=>{
      if(this.props.selectedLog == this.props.guid){
          return {color: 'red'}
      } else {
          return {color: '#85aef2'}
      }
  }
  selectLog = () => {
    if(this.props.selectedLog==this.props.guid){
        this.props.selectLog(-1);
    } else {
        this.props.selectLog(this.props.guid);
    }
  }
  render() {
    return (
      <Paper
       style={{marginBottom: '5px',flexDirection: 'column', display:'flex'}}
      >
      <div>
        <ParentLogEntry sender={this.props.log.sender} time={this.props.log.timestamp} guid={this.props.log.guid} />
        <ChildLogEntryContainer responses={this.props.log.responses} parentguid={this.props.log.guid}/>
      </div>
      </Paper>
    );
  }
}
const mapStateToProps = store =>{
    return {
        selectedLog: store.selectedLog.selectedLog,
    };
}
export default connect(mapStateToProps, {selectLog})(LogEntry);
