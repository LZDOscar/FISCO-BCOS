/*
 * @CopyRight:
 * FISCO-BCOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FISCO-BCOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>
 * (c) 2016-2018 fisco-dev contributors.
 */
/** @file BlockVerifierInterface.h
 *  @author mingzhenliu
 *  @date 20180921
 */
#pragma once

#include "Common.h"
#include "ExecutiveContext.h"
#include <libdevcore/FixedHash.h>
#include <libdevcore/easylog.h>
#include <libdevcrypto/Common.h>
#include <libethcore/Block.h>
#include <libethcore/Transaction.h>
#include <libethcore/TransactionReceipt.h>
#include <libevm/ExtVMFace.h>
#include <libexecutive/ExecutionResult.h>
#include <libmptstate/State.h>
#include <memory>

namespace dev
{
namespace eth
{
class PrecompiledContract;

}  // namespace eth
namespace blockverifier
{
class BlockVerifierInterface
{
public:
    BlockVerifierInterface() = default;

    virtual ~BlockVerifierInterface(){};

    virtual ExecutiveContext::Ptr executeBlock(
        dev::eth::Block& block, BlockInfo const& parentBlockInfo) = 0;
    virtual std::pair<dev::executive::ExecutionResult, dev::eth::TransactionReceipt>
    executeTransaction(
        const dev::eth::BlockHeader& blockHeader, dev::eth::Transaction const& _t) = 0;
};

}  // namespace blockverifier

}  // namespace dev
